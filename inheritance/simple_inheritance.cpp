
#include <iostream>
#include <format>

struct Parent {
        int one = 1;
        int two = 2;

        Parent() {
            std::cout << "ctor Parent\n";
        }

        int sum() {
            return one + two;
        }

        ~Parent() {
            std::cout << "dtor Parent\n";
        }
};

struct Derived : Parent {
        int three = 3;
        int four = 4;

        Derived() {
            std::cout << "ctor Derived\n";
        }

        int sum() {
            return three + four;
        }

        ~Derived() {
            std::cout << "dtor Derived\n";
        }
};

int main(int argc, char **argv) {
    Parent foo;
    Derived bar;

    std::cout << std::format("foo.sum() = {}\n", foo.sum());
    std::cout << std::format("bar.sum() = {}\n", bar.sum());

    return 0;
}
