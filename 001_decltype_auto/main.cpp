
#include <iostream>
#include <format>
#include <vector>

// #define ERROR_CASE

// CppCon 2014 Scott Mayers "Type deduction and why you care"
// decltype(auto) uses for force type deduction of return value (for instance)
// by decltype rules instead of auto (template) rules. In particular
// decltype preserve a const volatile and reference qualifiers.
// We can declare a return type as auto&, but sometimes a [] operator
// does't return reference - for instance vector<bool> ("vector of bool, sometimes it returns
// a proxy object" - Scott Mayers), see below;
decltype(auto) modifyAble(std::vector<int> &bar, size_t at) {
    if (bar.size() > at) {
        return bar[at];
    }
};

#ifdef ERROR_CASE
auto& maybeModifyAble(std::vector<bool> &bar, size_t at) {
    if (bar.size() > at) {
        return bar[at];
    }
}
#endif

// Sometimes decltype(auto) deduction rules are tricky....
// normal case
decltype(auto) lookup(float noMatter) {
    std::vector<int> bar(10, 100);
    auto foo = bar[9];
    return foo; // deduce int
}
// WARNING CASE, UB!!!
decltype(auto) lookup(int noMatter) {
    std::vector<int> bar(10, 100);
    auto foo = bar[9];
    return (foo); // deduce int&, a reference to local variable
}

int main(int argc, char **argv) {
    std::vector<int> bar(100, 0);

    modifyAble(bar, 5) = 101;

    std::cout << std::format("vector value at 5 = {}\n", bar[5]);
    
    return 0;
}
