# About
C++ example project with modern toolchain for STM32VLDISCOVERY board (MCU STM32F100RB)

# Building with LLVM-toolchain
You can build this project using `llvm` preset. This preset requires such tools: `clang`, `lld` and `ninja`. Use the following commands to build the project in debug mode:
```
cmake --preset llvm
cmake --build --preset debug
```
After that you can find builded ELF in `build/llvm` directory.