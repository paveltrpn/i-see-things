
#include <algorithm>
#include <iostream>
#include <format>
#include <memory>
#include <cstdint>
#include <string>

struct SomeGood {
        int32_t *good_;

        SomeGood(size_t amount) : good_{ new int32_t[amount] } {
            std::cout << "good created\n";
        }

        ~SomeGood() {
            delete[] good_;
            std::cout << "good destroyed\n";
        }
};

struct Parent {
        int one = 1;
        int two = 2;

        std::string name_;

        Parent(const std::string name) : name_{ name } {
            std::cout << std::format("ctor Parent {}\n", name_);
        }

        virtual ~Parent() {
            std::cout << std::format("dtor Parent {}\n", name_);
        }

        virtual int sum() {
            return one + two;
        }

        virtual int addSome(int addition) {
            return one + two + addition;
        }

        virtual std::string getName() {
            return name_;
        }
};

struct Son : Parent {
        int three = 3;
        int four = 4;

        std::string name_;

        Son(std::string name) : Parent("Parent"), name_{ name } {
            std::cout << std::format("ctor Son {}\n", name_);
        }

        ~Son() {
            std::cout << std::format("dtor Son {}\n", name_);
        }

        int sum() override {
            return three + four;
        }

        int addSome(int addition) override {
            return three + four + addition;
        }

        std::string getName() override {
            return name_;
        }

        std::string specific() {
            return "Son";
        }
};

struct GrandSon final : Son {
        int five = 5;
        int six = 6;

        std::string name_;

        GrandSon() : Son{ "Son" } {
            std::cout << std::format("ctor GrandSon {}\n", name_);
        }

        ~GrandSon() {
            std::cout << std::format("dtor GrandSon {}\n", name_);
        }

        int sum() override {
            return five + six;
        }

        std::string getName() override {
            return name_;
        }
};

int main(int argc, char **argv) {
    Parent foo{ "Chuck" };
    std::unique_ptr<Parent> bar = std::unique_ptr<Parent>{ new Son{ "Larry" } };
    // std::shared_ptr<Derived> bar = std::shared_ptr<Derived> {new Derived};
    // auto baz = std::shared_ptr<GrandSon>{new GrandSon};
    std::shared_ptr<Parent> baz = std::make_shared<GrandSon>();

    std::cout << "\n";

    std::cout << std::format("foo.sum() = {}\n", foo.sum());
    std::cout << std::format("bar.sum() = {}\n", bar->sum());
    std::cout << std::format("baz.sum() = {}\n", baz->sum());

    auto fromParent = std::make_unique<Parent>("Frank");
    std::cout << std::format("dynamic_cast from parent - {}\n",
                             dynamic_cast<Son *>(fromParent.get())->specific());

    std::cout << "\n";

    std::cout << std::format("foo.addSome() = {}\n", foo.addSome(10.f));
    std::cout << std::format("bar.addSome() = {}\n", bar->addSome(100.0f));

    std::cout << "\n";

    std::cout << std::format("Parent name - {}\n", foo.getName());
    std::cout << std::format("Son name - {}\n", bar->getName());
    std::cout << std::format("Grandson name - {}\n", baz->getName());

    std::cout << "\n";

    return 0;
}
