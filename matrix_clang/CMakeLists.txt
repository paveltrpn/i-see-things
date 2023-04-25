cmake_minimum_required(VERSION 3.0)

project (matrix)

set(CMAKE_C_COMPILER clang-15)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall \
-Wextra -Wpedantic -Wno-unused-parameter -std=c2x")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -fPIE -pie -fno-omit-frame-pointer -g")

set(LIBS -lm)

set(SOURCES main.c matrix.c)

add_executable(main ${SOURCES})
