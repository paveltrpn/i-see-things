
#include <cstdio>
#include <iostream>
#include <vector>

// Based on Arthur O'Dwyer - "Template normal programming (part 1)"

template <typename T>
struct SBar {
    private:
        std::vector<T> storage;
};

template <typename T>
void foo(T arg) {
    puts(__PRETTY_FUNCTION__);
}

int main(int argc, char **argv) {
    foo(1);
    foo(2.0f);
    foo(2.0);
    foo("hello");
    foo(SBar<float>{});
    foo(SBar<int>{});

    return 0;
}
