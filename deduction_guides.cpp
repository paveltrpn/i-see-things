
#include <iostream>
#include <format>

//
// CTAD - class template argument deduction guides
//

template<typename T>
struct SFoo {
    T field;
    std::string msg;

    SFoo(): msg{"SFoo default"} {

    }
    
    SFoo(double x) {
        field = x;
    }
    
    SFoo(T x, std::string m): msg{m} {
        field = x;
    }

    T get() {
        return field;
    }
};

//template<typename U>
//SFoo(U) -> SFoo<std::string>;

//SFoo(std::string) -> SFoo<int>;

template<typename T, typename U>
SFoo(T, U) -> SFoo<T>;

int main(int argc, char **argv) {
    std::cout << std::format("CTAD deducion guides\n");
    
    auto foo = SFoo(4., "asd");
    
    std::cout << std::format("SFoo.field - {}\n", foo.get());

    return 0;
}

