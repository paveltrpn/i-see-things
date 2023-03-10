cmake_minimum_required(VERSION 3.0)

project (matrix)

set(CMAKE_CXX_COMPILER clang++-15)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall \
-Wextra -Wpedantic -Wno-unused-parameter -std=c++20")

set(LIBS -lstdc++)

set(SOURCES main.cpp
            matrix.cpp)

add_executable(main ${SOURCES})
