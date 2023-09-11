
#include <iostream>
#include <format>
#include <memory>

int main(int argc, char **argv) {
    auto foo = std::make_shared<int>(10);

    auto fooPtr = foo.get();
    std::cout << std::format(
      "foo ptr - {:#010x} foo value - {}\n", reinterpret_cast<uintptr_t>(fooPtr), (*foo));

    // delete fooPtr; // may cause double deletion

    foo.reset(new int{ 20 });

    std::cout << std::format("replaced foo ptr - {:#010x} replaced foo value - {}\n",
                             reinterpret_cast<uintptr_t>(fooPtr),
                             (*foo));

    return 0;
}
