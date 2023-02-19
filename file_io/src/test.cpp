
#include <iostream>

#include "text_read.h"

int main(int argc, char **argv) {

    auto foo = textRead1("assets/raven.txt");
    std::cout << "  textRead1:\n" << foo.substr(10, 110) << "\n";

    auto bar = textRead2("assets/raven.txt");
    std::cout << "  textRead2:\n" << foo.substr(10, 110) << "\n";

    auto rab = textRead3("assets/raven.txt");
    std::cout << "  textRead3:\n" << rab.substr(131, 202) << "\n";

    auto [baz, tmp] = textReadToStrVec("assets/raven.txt");
    for (int i = 0; i < 3; i++) {
        std::cout << "textReadToStrVec:\n" << baz[i];
    }

    return 0;
}