#include <rcc.hpp>

extern "C" {

void SetSysClockToHSE(void) {
    std::uint32_t StartUpCounter = 0, HSEStatus = 0;
    std::uint16_t HSEStartUp_TimeOut = 0x500;

    auto cr = RCC::CR {};
    *(cr.get()) |= 0x10000; // Enable HSE

    // Wait till HSE is ready and if Time out is reached exit
    do {
        HSEStatus = *(cr.get()) & 0x20000;
        StartUpCounter++;
    } while ((HSEStatus == 0) && (StartUpCounter != HSEStartUp_TimeOut));

    if ((*(cr.get()) & 20000) != 0)
        HSEStatus = 0x01;
    else
        HSEStatus = 0x00;

    if (HSEStatus == 0x01) {
        auto cfgr = RCC::CFGR {};
        *(cfgr.get()) |= 0x00; // HCLK = SYSCLK
        *(cfgr.get()) |= 0x00; // PCLK2 = HCLK
        *(cfgr.get()) |= 0x00; // PCLK1 = HCLK

        // Select HSE as system clock source
        *(cfgr.get()) &= 0xfffffffc;
        *(cfgr.get()) |= 0x1;

        // Wait till HSE is used as system clock source
        while ((*(cfgr.get()) & 0xC) != 0x04) { }
    }
}

// Reset the RCC clock configuration to the default reset state(for debug purpose)
void SystemInit(void) {
    auto cr = RCC::CR {};
    *(cr.get()) |= 0x1; // Set HSION bit

    auto cfgr = RCC::CFGR {};
    *(cfgr.get()) &= 0xF8FF0000; // Reset SW, HPRE, PPRE1, PPRE2, ADCPRE and MCO bits

    *(cr.get()) &= 0xFEF6FFFF; // Reset HSEON, CSSON and PLLON bits
    *(cr.get()) &= 0xFFFBFFFF; // Reset HSEBYP bit

    *(cfgr.get()) &= 0xFF80FFFF; // Reset PLLSRC, PLLXTPRE, PLLMUL and USBPRE/OTGFSPRE bits

    auto cir = RCC::CIR {};
    *(cir.get()) = 0x009F0000; // Disable all interrupts, clear pending bits

    auto cfgr2 = RCC::CFGR2 {};
    *(cfgr2.get()) = 0x0; // Reset CFGR2 register

    SetSysClockToHSE();
}
}