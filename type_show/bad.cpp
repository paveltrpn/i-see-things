
#include <iostream>
#include <format>
#include <typeinfo>

struct Empty {

};

template <typename T>
void foo(const T& t) {
    // need demangle - c++filt -t {name}
    std::cout << std::format("type - {}\n", typeid(t).name());
}

int main(int argc, char *argv[]) {
    const Empty *bar;
    
    // typeid() cut "const" "ref" (appears in foo parameter) type qualifiers
    foo(bar);

    return 0;
}
