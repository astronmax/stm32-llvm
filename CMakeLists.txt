cmake_minimum_required(VERSION 3.16)
project(stm32-cpp ASM CXX)

# C++ standart
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# startup and linker scripts
set(STARTUP_SCRIPT ${CMAKE_SOURCE_DIR}/startup_stm32f10x_md_vl.s)
set(LD_SCRIPT ${CMAKE_SOURCE_DIR}/stm32f100rb_flash.x)

# project source files
file(GLOB PROJECT_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# target executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${STARTUP_SCRIPT})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} -T ${LD_SCRIPT} ${LD_FLAGS})

# C++ minimal STL
set(STL_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/stl/include)
file (GLOB STL_LIBRARY ${CMAKE_SOURCE_DIR}/src/lib/*.a)
target_include_directories(${PROJECT_NAME} PUBLIC ${STL_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${STL_LIBRARY})