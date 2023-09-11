
#include <iostream>
#include <format>
#include <typeinfo>

struct Empty {};

template <typename T>
class type2type {};

template <typename T>
void foo(const T &t) {
    // need demangle - c++filt -t {name}
    type2type<decltype(t)> t2t;
    std::cout << std::format("type - {}\n", typeid(t2t).name());
}

int main(int argc, char *argv[]) {
    const Empty *bar;

    // typeid() cut "const" "ref" (appears in foo parameter) type qualifiers
    foo(bar);

    return 0;
}
