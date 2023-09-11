//
// #include <iostream>
//
#include "matrix.h"

int main() {
    auto foo = matrix_c<float>{ 4, 4 };
    foo.setIdtt();
    matrix_c<float> bar{ std::move(foo) };

    // Constrains not satisfied for class template 'matrix_c' [with T = int]
    // matrix_c<int> baz{100, 100};

    bar.print();
    // auto baz = foo;
    // bar = std::move(baz);
    //
    // std::cout << "foo\n";
    // foo.print();

    // std::cout << "bar\n";
    // bar.print();

    // std::cout << "baz\n";
    // baz.print();

    return 0;
}
