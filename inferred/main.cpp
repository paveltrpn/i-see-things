
// LSP or compiler trace show iferred types in templates

#include <iostream>
#include <vector>

template <class Type> struct S;

class moveable_c {
    public:
        moveable_c() {
        }
        moveable_c(const moveable_c &rhs) {
        }
        moveable_c(moveable_c &&rhs){};

        moveable_c &&operator=(moveable_c &&rhs) {
            return std::move(moveable_c());
        }
};

int main() {
    int beg = 10;
    int &int_ref = beg;
    auto &bb = const_cast<const int &>(int_ref);

    S<decltype(bb)>();

    for (auto i = 0; i < 100; i++) {
        S<decltype(i)>();
    }

    auto x = 10;
    S<decltype(x)>();

    std::vector<moveable_c> foo{};
    for (auto &elem : foo) {
        moveable_c t;

        S<decltype(std::move(elem))>();
    }

    return 0;
}
