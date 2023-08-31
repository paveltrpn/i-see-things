
// test of C++26 "underscore - _" variable, that supports in clang-18

#include <iostream>
#include <format>
#include <utility>

auto getPair(std::string first, float second) -> std::pair<decltype(first), decltype(second)> {
    return std::make_pair(first, second);
}

int main(int argc, char **argv) {
    auto [one, _] = getPair("one", 2.0f);

    std::cout << std::format("first of - {}\n", one);

    return 0;
}
