cmake_minimum_required(VERSION 3.20)

set(CMAKE_C_COMPILER clang)
set(CMAKE_CXX_COMPILER clang++)

project (cpp-playground)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

add_compile_options(-g -Wall -Wextra -Wpedantic -std=c++20 -stdlib=libc++ -Wno-unused-parameter)
add_link_options(-stdlib=libc++)

add_subdirectory(junior_example)
add_subdirectory(scope_aware_thread)
add_subdirectory(inheritance)
add_subdirectory(cppcoro)
add_subdirectory(placeholder_variable)
add_subdirectory(SFINAE)
add_subdirectory(template_syntax)
add_subdirectory(euclid-template)
add_subdirectory(001_decltype_auto)
add_subdirectory(002_recursive_lock)
