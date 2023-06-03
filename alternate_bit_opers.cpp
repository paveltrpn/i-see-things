
#include <iostream>
#include <format>
#include <expected>

int main(int argc, char *argv[]) {
    bool tru = true;
    bool fls = false;

    std::cout << std::format("and = {}, or = {}, not tru = {}\n", 
            // watch Grill the Committee - 2017 and first time i heard about
            // bit operators named like that.
            tru and fls, tru or fls, not tru);
}
