#pragma once

template <typename addr_type, typename val_type, const addr_type addr, const val_type val>
class reg_access {
public:
    static void reg_set() {
        *reinterpret_cast<volatile val_type*>(addr) = val;
    }

    static void reg_or() {
        *reinterpret_cast<volatile val_type*>(addr) |= val;
    }

    static void reg_and() {
        *reinterpret_cast<volatile val_type*>(addr) &= val;
    }

    static val_type reg_get() {
        return *reinterpret_cast<volatile val_type*>(addr);
    }

    static void bit_set() {
        *reinterpret_cast<volatile val_type*>(addr) |= (0b1 << val);
    }

    static void bit_not() {
        *reinterpret_cast<volatile val_type*>(addr) ^= (0b1 << val);
    }

    static void bit_clr() {
        *reinterpret_cast<volatile val_type*>(addr) &= ~(addr_type((0b1 << val)));
    }

    static val_type bit_get() {
        return ((*reinterpret_cast<volatile val_type*>(addr) & (0b1 << val)) >> val);
    }
};
