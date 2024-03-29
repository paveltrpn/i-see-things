
#include <format>
#include <iostream>

class Foo {
    public:
        Foo(int a, int b, int c) : a_{ a }, b_{ b }, c_{ c } {
        }
        int a_, b_, c_;

        friend std::ostream &operator<<(std::ostream &os, Foo &rhs);
};

auto operator<<(std::ostream &os, Foo &rhs) -> std::ostream & {
    os << rhs.a_ << " " << rhs.b_ << " " << rhs.c_;
    return os;
}

auto main() -> int {
    Foo one(100, 211, 233);
    Foo two(one);
    Foo three = two;

    std::cout << std::format("{} {}\n", "hello", "format");

    std::cout << "one - " << one << "\n";
    std::cout << "two - " << two << "\n";
    std::cout << "three - " << three << "\n";
    return 0;
}
