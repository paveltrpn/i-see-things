
#include <iostream>
#include <vector>
#include <format>

int main() {
    // Grill the Committee 2018 - Herb Sutter first reason to
    // use almost always auto is - not forget to initialise
    // variable by some value, not deduction reason.
    // And c++17 it guarantie move elision
    auto x = std::vector<int>{};

    x.emplace_back(0);

    std::cout << std::format("is - {}\n", x[0]);
}
