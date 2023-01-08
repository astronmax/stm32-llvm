#include <cstdint>
#include <reg.hpp>

using u32 = std::uint32_t;
using u16 = std::uint16_t;

auto main() -> int {
    const auto abp2enr = UINT32_C(0x40021018);
    const auto gpioc_chr = UINT32_C(0x40011004);
    const auto gpioc_bssr = UINT32_C(0x40011010);

    // enable GPIOC
    reg_access<u32, u32, abp2enr, 4>::bit_set();

    // set PC8 and PC9 to output mode
    reg_access<u32, u32, gpioc_chr, 0xffffff00>::reg_and(); // reset previous value
    reg_access<u32, u32, gpioc_chr, 0b00010001>::reg_or(); // set needed mode and cnf

    // set PC8 and PC9 with BSSR
    reg_access<u32, u16, gpioc_bssr, 8>::bit_set();
    reg_access<u32, u16, gpioc_bssr, 9>::bit_set();
}
