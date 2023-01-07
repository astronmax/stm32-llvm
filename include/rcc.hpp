#pragma once

#include <cstdint>

namespace RCC {

constexpr std::uint32_t RCC_BASE = UINT32_C(0x40021000);

class CR {
private:
    std::uint32_t* addr;

public:
    CR()
        : addr { reinterpret_cast<std::uint32_t*>(RCC_BASE + 0x00) } { }

    ~CR() = default;

    auto get() -> std::uint32_t* {
        return addr;
    }
};

class CFGR {
private:
    std::uint32_t* addr;

public:
    CFGR()
        : addr { reinterpret_cast<std::uint32_t*>(RCC_BASE + 0x04) } { }

    ~CFGR() = default;

    auto get() -> std::uint32_t* {
        return addr;
    }
};

class CIR {
private:
    std::uint32_t* addr;

public:
    CIR()
        : addr { reinterpret_cast<std::uint32_t*>(RCC_BASE + 0x08) } { }

    ~CIR() = default;

    auto get() -> std::uint32_t* {
        return addr;
    }
};

class CFGR2 {
private:
    std::uint32_t* addr;

public:
    CFGR2()
        : addr { reinterpret_cast<std::uint32_t*>(RCC_BASE + 0x2C) } { }

    ~CFGR2() = default;

    auto get() -> std::uint32_t* {
        return addr;
    }
};

}