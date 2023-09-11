
#include <iostream>
#include <format>

struct Foo {
        Foo() = default;
        Foo(int i_, int j_) : i{ i_ }, j{ j_ } {};

        int i;
        int j;
};

int main(int argc, char *argv[]) {
    int i;     // default init, C
    Foo foo1;  // same, if Foo is POD (C struct)
               // return foo1.i - UB

    int j = 43;  // copy init, C

    int n[4] = { 0, 1, 2, 3 };  // aggregate init, C
    Foo foo2 = { 1, 2 };        // same, if Foo is POD (C struct)

    static int m = 3;  // static init, C
    static int u;      // same, u = 0

    return 0;
}
