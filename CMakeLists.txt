cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project (cpp-playground)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall \
                                        -Wextra \
                                        -Wpedantic \
                                        -Wno-unused-parameter \
                                        --std=c++2b \
                                        --stdlib=libc++")

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_subdirectory(junior_example)
add_subdirectory(scope_aware_thread)
add_subdirectory(inheritance)
add_subdirectory(cppcoro)
add_subdirectory(placeholder_variable)
