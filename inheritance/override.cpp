
#include <algorithm>
#include <iostream>
#include <format>
#include <memory>

struct Parent {
        int one = 1;
        int two = 2;

        Parent() {
            std::cout << "ctor Parent\n";
        }

        virtual int sum() {
            return one + two;
        }

        virtual int addSome(int addition) {
            return one + two + addition;
        }

        virtual ~Parent() {
            std::cout << "dtor Parent\n";
        }
};

struct Derived : Parent {
        int three = 3;
        int four = 4;

        Derived() {
            std::cout << "ctor Derived\n";
        }

        virtual int sum() override {
            return three + four;
        }

        int addSome(int addition) override {
            return three + four + addition;
        }

        ~Derived() {
            std::cout << "dtor Derived\n";
        }
};

int main(int argc, char **argv) {
    Parent foo;
    std::unique_ptr<Parent> bar = std::unique_ptr<Parent>{ new Derived };
    // std::shared_ptr<Derived> bar = std::shared_ptr<Derived> {new Derived};

    std::cout << "\n";

    std::cout << std::format("foo.sum() = {}\n", foo.sum());
    std::cout << std::format("bar.sum() = {}\n", bar->sum());

    std::cout << "\n";

    std::cout << std::format("foo.addSome() = {}\n", foo.addSome(10.f));
    std::cout << std::format("bar.addSome() = {}\n", bar->addSome(100.0f));

    std::cout << "\n";

    return 0;
}
