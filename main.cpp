// main.cpp - Verilator C++ harness for TopLayer (NOVA CPU).
//
// What this does:
//   1. Instantiates TopLayer (built with its default parameters -- see
//      obj_dir/VTopLayer_classes.mk / TopLayer.v: BOOTLOADER=1,
//      CLKS_PER_BIT=16 -- so the compiled model already contains the UART
//      bootloader preloaded into BRAM at address 0, exactly like BootTb.v).
//   2. Bit-bangs a length-prefixed program over uart_rx[0] using the same
//      8N1 framing BootTb.v uses, so the bootloader stores it at
//      PROG_BASE=0x1000 and jumps there.
//   3. The program loaded (fib_program below) is interrupt-driven: it
//      installs a trap handler, enables the external interrupt, and then
//      services GPIO and all 4 UARTs by draining whatever arrives into a
//      per-device software ring buffer in RAM (see the "input subsystem"
//      block comment further down for the full design). The main flow
//      pulls one byte from UART0's buffer via a generic GET_INPUT routine,
//      computes fib(N), and reports the result both over GPIO_DATA_OUT
//      (with a "done" flag bit) and as raw bytes over UART0 TX.
//   4. This harness sends N as a single byte over UART0 -- at any point
//      after the bootload transfer finishes, with no need to wait for the
//      CPU to reach any particular point in its own program, because the
//      interrupt handler buffers it whenever it arrives. It then reads the
//      result back both ways and prints both.
//
// All communication with the simulated CPU (bootloading, UART, GPIO, and
// the clock itself) is wrapped in the NovaSim class below so call sites
// don't need to know about clock stepping or bit timing.
//
// Wire protocols used by fib_program (see TopLayer.v's MMIO map):
//   UART0 rx: a single byte, N, any time after the program is loaded
//   gpio_out bit31 = "result ready", bits[30:0] = fib(N)
//   UART0 tx: raw 32-bit fib(N), 4 bytes, little-endian, sent once
// (fib(N) is exact for N <= 46; the GPIO result is truncated to 31 bits
// above that, while the UART result carries the full 32-bit value.)
//
// ---------------------------------------------------------------------
// Input subsystem (interrupt-driven, buffered, multi-device)
// ---------------------------------------------------------------------
// Devices: 0=GPIO, 1=UART0, 2=UART1, 3=UART2, 4=UART3.
//
// RAM layout (fixed addresses, chosen to sit in the free space below
// PROG_BASE=0x1000 -- BRAM is zero-initialized at elaboration, so these
// start out empty with no explicit setup needed):
//   0x0100..0x037F  5 device records, 128 bytes apart (device_id << 7):
//     +0   head (word index into buf[], written only by the producer)
//     +4   tail (word index into buf[], written only by the consumer)
//     +16  buf[16] (16 words = 64 bytes; index is masked mod 16, so the
//                   buffer holds up to 15 entries -- full is defined as
//                   "one slot short of colliding with tail")
//   0xFFF0          initial stack pointer (sp = x2), grows down
//
// Every entry is stored as a plain 32-bit word regardless of device (a
// UART byte is zero-extended into a word) so one generic routine can serve
// every device without branching on element size.
//
// ISR (installed at mtvec, entered on any external interrupt):
//   Saves every register it touches (x1, x5-x11) to the stack, confirms
//   mcause is the external-interrupt cause, then reads IRQ_SOURCE and, for
//   each pending device: GPIO gets its current GPIO_DATA_IN word pushed
//   once and its INT_PENDING bits cleared; each UART gets fully drained
//   (looping while its STATUS.RX_VALID bit is set, since the hardware RX
//   FIFO can hold several bytes) via a shared DRAIN_UART helper. Restores
//   all saved registers and MRETs. Because bytes land in the UART's own
//   8-deep hardware FIFO the instant they arrive -- independent of whether
//   interrupts are enabled yet -- nothing is lost even if the host sends a
//   byte before the CPU has finished its own interrupt setup.
//
// PUSH_INPUT (in: x10=device_id, x11=value; ISR-internal, only touches
// x10/x11) and GET_INPUT (in: x10=device_id; out: x10=data, x11=status --
// 0=OK, 1=EMPTY; the only routine the main program calls) share the same
// record layout and 2-register calling convention: every other register
// they use (x12-x14, and ra/x1 for GET_INPUT's own call frame) is saved to
// the stack on entry and restored before return, so callers never need to
// protect anything beyond the input/output registers themselves. Producer
// (PUSH_INPUT) writes only `head` and reads only `tail`; consumer
// (GET_INPUT) writes only `tail` and reads only `head` -- that split is
// what makes it safe for an interrupt to land in the middle of a GET_INPUT
// call without corrupting either side, with no locking needed.
//
// On overflow (head would collide with tail), PUSH_INPUT silently drops
// the new value rather than blocking inside an ISR.
//
// fib_program's MAIN loop is the simplest possible consumer -- wait for
// exactly one item:
//   MAIN: x10=1 (UART0); call GET_INPUT; if status==EMPTY, loop back to
//   MAIN; otherwise x10 holds the byte, treat it as N.
// A generic "drain everything queued right now" consumer looks almost
// identical, just with the branch flipped: call GET_INPUT, if status==OK
// handle x10 and loop back, if status==EMPTY stop. Either shape is built
// from the same GET_INPUT primitive.

#include "VTopLayer.h"
#include "VTopLayer___024root.h"
#include "verilated.h"

#include <chrono>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <memory>
#include <optional>
#include <thread>
#include <vector>

// ---- hand-assembled RV32I input-buffering + Fibonacci program ----
// (see the input-subsystem block comment above; loaded at PROG_BASE=0x1000)
static const std::vector<uint32_t> fib_program = {
    0x00010137u, // lui x2,0x10
    0xff010113u, // addi x2,x2,-16
    0x000012b7u, // lui x5,0x1
    0x1cc28293u, // addi x5,x5,460
    0x30529073u, // csrrw x0,0x305,x5
    0xf4000313u, // addi x6,x0,-192
    0x00100393u, // addi x7,x0,1
    0x00732423u, // sw x7,8(x6)
    0xf0000313u, // addi x6,x0,-256
    0xfff00393u, // addi x7,x0,-1
    0x00732423u, // sw x7,8(x6)
    0x00732a23u, // sw x7,20(x6)
    0x00732c23u, // sw x7,24(x6)
    0x00732e23u, // sw x7,28(x6)
    0x00800393u, // addi x7,x0,8
    0x3003a073u, // csrrs x0,0x300,x7
    0x00100393u, // addi x7,x0,1
    0x00b39393u, // slli x7,x7,11
    0x3043a073u, // csrrs x0,0x304,x7
    0x00100513u, // MAIN: addi x10,x0,1
    0x090000efu, // jal x1,GET_INPUT
    0x00058463u, // beq x11,x0,GOT_N
    0xff5ff06fu, // jal x0,MAIN
    0x00050293u, // GOT_N: addi x5,x10,0
    0x00000393u, // addi x7,x0,0
    0x00100413u, // addi x8,x0,1
    0x02028463u, // beq x5,x0,SKIP
    0xfff28493u, // addi x9,x5,-1
    0x00048c63u, // LOOP: beq x9,x0,SKIP2
    0x008385b3u, // add x11,x7,x8
    0x00040393u, // addi x7,x8,0
    0x00058413u, // addi x8,x11,0
    0xfff48493u, // addi x9,x9,-1
    0xfedff06fu, // jal x0,LOOP
    0x00040313u, // SKIP2: addi x6,x8,0
    0x0080006fu, // jal x0,OUT
    0x00038313u, // SKIP: addi x6,x7,0
    0xf0000093u, // OUT: addi x1,x0,-256
    0x800006b7u, // lui x13,0x80000
    0x00131713u, // slli x14,x6,1
    0x00175713u, // srli x14,x14,1
    0x00e6e7b3u, // or x15,x13,x14
    0x00f0a223u, // sw x15,4(x1)
    0xf4000813u, // addi x16,x0,-192
    0x00030913u, // addi x18,x6,0
    0x00400893u, // addi x17,x0,4
    0x02088263u, // UBYTE: beq x17,x0,UDONE
    0x00482983u, // UWAIT: lw x19,4(x16)
    0x0019f993u, // andi x19,x19,1
    0xfe098ce3u, // beq x19,x0,UWAIT
    0x0ff97a13u, // andi x20,x18,255
    0x01482023u, // sw x20,0(x16)
    0x00895913u, // srli x18,x18,8
    0xfff88893u, // addi x17,x17,-1
    0xfe1ff06fu, // jal x0,UBYTE
    0x0000006fu, // UDONE,SPIN: jal x0,SPIN
    0xff410113u, // GET_INPUT: addi x2,x2,-12
    0x00c12023u, // sw x12,0(x2)
    0x00d12223u, // sw x13,4(x2)
    0x00e12423u, // sw x14,8(x2)
    0x00751613u, // slli x12,x10,7
    0x10000693u, // addi x13,x0,256
    0x00d60633u, // add x12,x12,x13
    0x00062683u, // lw x13,0(x12)
    0x00462703u, // lw x14,4(x12)
    0x02e68263u, // beq x13,x14,GI_EMPTY
    0x00271693u, // slli x13,x14,2
    0x00c686b3u, // add x13,x13,x12
    0x0106a503u, // lw x10,16(x13)
    0x00170713u, // addi x14,x14,1
    0x00f77713u, // andi x14,x14,15
    0x00e62223u, // sw x14,4(x12)
    0x00000593u, // addi x11,x0,0
    0x00c0006fu, // jal x0,GI_DONE
    0x00000513u, // GI_EMPTY: addi x10,x0,0
    0x00100593u, // addi x11,x0,1
    0x00012603u, // GI_DONE: lw x12,0(x2)
    0x00412683u, // lw x13,4(x2)
    0x00812703u, // lw x14,8(x2)
    0x00c10113u, // addi x2,x2,12
    0x00008067u, // jalr x0,0(x1)
    0xff410113u, // PUSH_INPUT: addi x2,x2,-12
    0x00c12023u, // sw x12,0(x2)
    0x00d12223u, // sw x13,4(x2)
    0x00e12423u, // sw x14,8(x2)
    0x00751613u, // slli x12,x10,7
    0x10000693u, // addi x13,x0,256
    0x00d60633u, // add x12,x12,x13
    0x00062683u, // lw x13,0(x12)
    0x00462703u, // lw x14,4(x12)
    0x00168513u, // addi x10,x13,1
    0x00f57513u, // andi x10,x10,15
    0x00e50a63u, // beq x10,x14,PI_FULL
    0x00269713u, // slli x14,x13,2
    0x00c70733u, // add x14,x14,x12
    0x00b72823u, // sw x11,16(x14)
    0x00a62023u, // sw x10,0(x12)
    0x00012603u, // PI_FULL: lw x12,0(x2)
    0x00412683u, // lw x13,4(x2)
    0x00812703u, // lw x14,8(x2)
    0x00c10113u, // addi x2,x2,12
    0x00008067u, // jalr x0,0(x1)
    0xffc10113u, // DRAIN_UART: addi x2,x2,-4
    0x00112023u, // sw x1,0(x2)
    0x00432403u, // DU_LOOP: lw x8,4(x6)
    0x00447413u, // andi x8,x8,4
    0x00040c63u, // beq x8,x0,DU_DONE
    0x00032483u, // lw x9,0(x6)
    0x00038513u, // addi x10,x7,0
    0x00048593u, // addi x11,x9,0
    0xf8dff0efu, // jal x1,PUSH_INPUT
    0xfe5ff06fu, // jal x0,DU_LOOP
    0x00012083u, // DU_DONE: lw x1,0(x2)
    0x00410113u, // addi x2,x2,4
    0x00008067u, // jalr x0,0(x1)
    0xfe010113u, // ISR: addi x2,x2,-32
    0x00112023u, // sw x1,0(x2)
    0x00512223u, // sw x5,4(x2)
    0x00612423u, // sw x6,8(x2)
    0x00712623u, // sw x7,12(x2)
    0x00812823u, // sw x8,16(x2)
    0x00912a23u, // sw x9,20(x2)
    0x00a12c23u, // sw x10,24(x2)
    0x00b12e23u, // sw x11,28(x2)
    0x342022f3u, // csrrs x5,0x342,x0
    0x800004b7u, // lui x9,0x80000
    0x00b4e493u, // ori x9,x9,11
    0x06929e63u, // bne x5,x9,ISR_DONE
    0xfa000393u, // addi x7,x0,-96
    0x0003a403u, // lw x8,0(x7)
    0x00147493u, // andi x9,x8,1
    0x00048e63u, // beq x9,x0,ISR_U0
    0x00000513u, // addi x10,x0,0
    0xf0000313u, // addi x6,x0,-256
    0x00032583u, // lw x11,0(x6)
    0xf29ff0efu, // jal x1,PUSH_INPUT
    0xfff00593u, // addi x11,x0,-1
    0x02b32023u, // sw x11,32(x6)
    0x00247493u, // ISR_U0: andi x9,x8,2
    0x00048863u, // beq x9,x0,ISR_U1
    0x00100393u, // addi x7,x0,1
    0xf4000313u, // addi x6,x0,-192
    0xf61ff0efu, // jal x1,DRAIN_UART
    0x00447493u, // ISR_U1: andi x9,x8,4
    0x00048863u, // beq x9,x0,ISR_U2
    0x00200393u, // addi x7,x0,2
    0xf5000313u, // addi x6,x0,-176
    0xf4dff0efu, // jal x1,DRAIN_UART
    0x00847493u, // ISR_U2: andi x9,x8,8
    0x00048863u, // beq x9,x0,ISR_U3
    0x00300393u, // addi x7,x0,3
    0xf6000313u, // addi x6,x0,-160
    0xf39ff0efu, // jal x1,DRAIN_UART
    0x01047493u, // ISR_U3: andi x9,x8,16
    0x00048863u, // beq x9,x0,ISR_DONE
    0x00400393u, // addi x7,x0,4
    0xf7000313u, // addi x6,x0,-144
    0xf25ff0efu, // jal x1,DRAIN_UART
    0x00012083u, // ISR_DONE: lw x1,0(x2)
    0x00412283u, // lw x5,4(x2)
    0x00812303u, // lw x6,8(x2)
    0x00c12383u, // lw x7,12(x2)
    0x01012403u, // lw x8,16(x2)
    0x01412483u, // lw x9,20(x2)
    0x01812503u, // lw x10,24(x2)
    0x01c12583u, // lw x11,28(x2)
    0x02010113u, // addi x2,x2,32
    0x30200073u, // mret
};

// Thin, reusable wrapper around a VTopLayer instance. Hides clock stepping,
// clock-rate pacing, and UART bit timing behind small blocking calls so
// callers just talk in terms of bytes/words/GPIO values.
class NovaSim {
public:
    using Clock = std::chrono::steady_clock;

    // Running tally of how the clock has actually behaved, as opposed to
    // what was asked for via setClockFrequencyHz().
    struct ClockStats {
        uint64_t ticks = 0;
        std::chrono::nanoseconds wallTime{ 0 };

        double observedHz() const {
            const double secs = std::chrono::duration<double>(wallTime).count();
            return secs > 0.0 ? static_cast<double>(ticks) / secs : 0.0;
        }
    };

    NovaSim() {
        contextp_ = std::make_unique<VerilatedContext>();
        top_ = std::make_unique<VTopLayer>(contextp_.get());
    }

    VTopLayer* top() { return top_.get(); }

    // ---- clock rate control ----

    // Pace step() to approximate this frequency in real (wall-clock) time,
    // e.g. setClockFrequencyHz(200e6) for a 200MHz clock. Pass 0 (the
    // default) to run unpaced, as fast as the host can go. Note that real
    // per-cycle pacing has a floor set by OS scheduling/timer resolution
    // (typically low microseconds) -- ask for a rate faster than the host
    // (and this floor) can sustain and step() will simply run flat-out;
    // clockStats() tells you what you actually got.
    void setClockFrequencyHz(double hz) {
        targetPeriod_ = hz > 0.0 ? std::chrono::duration<double>(1.0 / hz)
            : std::chrono::duration<double>(0.0);
    }

    const ClockStats& clockStats() const { return stats_; }
    void resetClockStats() { stats_ = ClockStats{}; }

    // ---- clock stepping ----

    // One full clk cycle (0 -> 1 -> 0), optionally paced to the configured
    // clock frequency. Set any inputs before calling this so they're stable
    // across the posedge that the design samples on.
    void step() {
        const auto t0 = Clock::now();

        top_->clk = 0;
        top_->eval();
        contextp_->timeInc(1);
        top_->clk = 1;
        top_->eval();
        contextp_->timeInc(1);
        top_->clk = 0;
        top_->eval();
        contextp_->timeInc(1);

        if (targetPeriod_.count() > 0.0) {
            if (stats_.ticks == 0) nextTick_ = t0;
            nextTick_ += std::chrono::duration_cast<Clock::duration>(targetPeriod_);
            paceUntil(nextTick_);
        }

        stats_.ticks++;
        stats_.wallTime +=
            std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - t0);
    }

    void stepN(int n) {
        for (int i = 0; i < n; ++i) step();
    }

    void reset(int cycles = 10) {
        top_->rst = 1;
        top_->irq_external = 0;
        top_->uart_rx = 0xF; // idle (all 4 UART rx lines high)
        top_->gpio_in = 0;
        stepN(cycles);
        top_->rst = 0;
        stepN(cycles); // settle before toggling uart_rx
    }

    // ---- UART0, host -> CPU (bit-bang transmit, 8N1, LSB first) ----

    void uartSendByte(uint8_t b) {
        holdBit(0); // start bit
        for (int k = 0; k < 8; ++k) holdBit((b >> k) & 1);
        holdBit(1); // stop bit
    }

    void uartSendWord32(uint32_t w) {
        uartSendByte(static_cast<uint8_t>(w));
        uartSendByte(static_cast<uint8_t>(w >> 8));
        uartSendByte(static_cast<uint8_t>(w >> 16));
        uartSendByte(static_cast<uint8_t>(w >> 24));
    }

    // ---- UART0, CPU -> host (bit-bang receive, 8N1, LSB first) ----
    // std::nullopt on timeout.

    std::optional<uint8_t> uartRecvByte(long long maxCycles = 1'000'000) {
        long long budget = maxCycles;
        while (top_->uart_tx & 1) { // wait for start bit (line idle-high)
            step();
            if (--budget <= 0) return std::nullopt;
        }
        stepN(kClksPerBit - 1); // finish the start-bit period
        uint8_t b = 0;
        for (int k = 0; k < 8; ++k) {
            stepN(kClksPerBit);
            if (top_->uart_tx & 1) b |= static_cast<uint8_t>(1u << k);
        }
        stepN(kClksPerBit); // stop bit
        return b;
    }

    std::optional<uint32_t> uartRecvWord32(long long maxCyclesPerByte = 1'000'000) {
        uint32_t w = 0;
        for (int i = 0; i < 4; ++i) {
            const auto b = uartRecvByte(maxCyclesPerByte);
            if (!b) return std::nullopt;
            w |= static_cast<uint32_t>(*b) << (8 * i);
        }
        return w;
    }

    // ---- GPIO ----

    void gpioWrite(uint32_t value) { top_->gpio_in = value; }
    uint32_t gpioRead() const { return top_->gpio_out; }

    // Step until (gpio_out & mask) != 0, or give up after maxCycles.
    bool gpioWaitFlag(uint32_t mask, long long maxCycles = 2'000'000) {
        long long cycles = 0;
        while (!(top_->gpio_out & mask)) {
            step();
            if (++cycles >= maxCycles) return false;
        }
        return true;
    }

    // ---- program load ----

    // Sends [word count][program words...] over uart_rx[0] per the on-chip
    // bootloader's protocol (see BootTb.v / TopLayer.v's boot_preload).
    void loadProgramViaBootloader(const std::vector<uint32_t>& words) {
        uartSendWord32(static_cast<uint32_t>(words.size()));
        for (uint32_t w : words) uartSendWord32(w);
        stepN(50); // let the loader store the last word and jump
    }

    // ---- debug ----

    void printDebugState() const {
        std::fprintf(stderr, "PC=%08x gpio_out=%08x\n",
            top_->rootp->TopLayer__DOT__cpu__DOT__PC, top_->gpio_out);
    }

private:
    void holdBit(int level) {
        // uart_rx[3:1] stay idle (1); only uart_rx[0] (UART0) is driven.
        top_->uart_rx = static_cast<uint8_t>(0xE | (level & 1));
        stepN(kClksPerBit);
    }

    // Sleep/spin until `target`, without ever oversleeping: coarse
    // std::this_thread::sleep_for for the bulk of the wait (cheap on the
    // host, but only accurate to the OS scheduler's resolution), then a
    // tight spin for the last ~1ms to land on `target` precisely.
    static void paceUntil(Clock::time_point target) {
        auto now = Clock::now();
        if (target <= now) return; // already behind schedule; don't try to catch up
        auto remaining = target - now;
        constexpr auto kSpinWindow = std::chrono::milliseconds(1);
        if (remaining > kSpinWindow) {
            std::this_thread::sleep_for(remaining - kSpinWindow);
        }
        while (Clock::now() < target) {
            // busy-spin for final precision
        }
    }

    static constexpr int kClksPerBit = 16; // must match TopLayer's CLKS_PER_BIT

    std::unique_ptr<VerilatedContext> contextp_;
    std::unique_ptr<VTopLayer> top_;

    std::chrono::duration<double> targetPeriod_{ 0.0 }; // 0 = unpaced
    Clock::time_point nextTick_{};
    ClockStats stats_;
};

namespace {

    void printClockStats(const NovaSim::ClockStats& stats, const char* label) {
        const double ms = std::chrono::duration<double, std::milli>(stats.wallTime).count();
        std::cout << label << ": " << stats.ticks << " clk ticks in " << ms
            << " ms (observed " << stats.observedHz() / 1.0e6 << " MHz)\n";
    }

} // namespace

int main(int argc, char** argv) {
    constexpr double kTargetClockHz = 200e6; // e.g. 200MHz -- tune to taste

    NovaSim sim;
    sim.top()->contextp()->commandArgs(argc, argv);
    sim.setClockFrequencyHz(kTargetClockHz);

    sim.reset();
    sim.loadProgramViaBootloader(fib_program);
    printClockStats(sim.clockStats(), "reset + bootload");
    sim.resetClockStats();

    std::cout << "Enter n for fib(n) (0-255): ";
    int n = 0;
    if (!(std::cin >> n) || n < 0 || n > 255) {
        std::cerr << "Please enter an integer between 0 and 255.\n";
        return 1;
    }

    // No synchronization with the CPU's own program state needed here --
    // just send the byte. The interrupt handler buffers it whenever it
    // arrives (even if it arrives before the CPU has finished enabling
    // interrupts, since it lands in UART0's own hardware FIFO regardless).
    sim.uartSendByte(static_cast<uint8_t>(n));

    if (!sim.gpioWaitFlag(0x80000000u)) {
        std::cerr << "Timed out waiting for GPIO result.\n";
        sim.printDebugState();
        return 1;
    }
    uint32_t gpioResult = sim.gpioRead() & 0x7FFFFFFFu;
    std::cout << "GPIO result: fib(" << n << ") = " << gpioResult << "\n";

    const auto uartResult = sim.uartRecvWord32();
    if (!uartResult) {
        std::cerr << "Timed out waiting for UART result.\n";
        sim.printDebugState();
        return 1;
    }
    std::cout << "UART result: fib(" << n << ") = " << *uartResult << "\n";
    printClockStats(sim.clockStats(), "compute + readback");

    if (n <= 46 && gpioResult != *uartResult) {
        std::cerr << "warning: GPIO and UART results disagree!\n";
    }
    if (n >= 47) {
        std::cout << "(note: fib(" << n << ") overflows 31 bits, so the "
            "GPIO and UART readings diverge above -- UART carries "
            "the true 32-bit wrapped value)\n";
    }

    sim.top()->final();
    return 0;
}

// Required by the Verilator runtime for $time / trace timestamping even
// though this harness doesn't use SystemC -- without it, linking fails.
double sc_time_stamp() {
    return 0;
}
