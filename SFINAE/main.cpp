
#include <format>
#include <iostream>

#include "old_sfinae.h"

template <typename T> const bool has_typedef_foobar<T>::value = (sizeof(test<T>(0)) == sizeof(yes));

struct foo {
        typedef float foobar;
};

struct bar {};

int main() {
    std::cout << std::format("old sfinae case\n");
    std::cout << std::format("foo is - {}\n", has_typedef_foobar<foo>::value);
    std::cout << std::format("bar is - {}\n", has_typedef_foobar<bar>::value);

    float one;
    // called "no" because template parametrized by foo with not float& argument
    has_typedef_foobar<bar>::test<foo>(2.0f);
    // called "yes" because template parametrized by foo with exactly float& argument
    has_typedef_foobar<bar>::test<foo>(&one);
    // this two below called with "no" because no mater whitch argument has passed
    // either float& or any other - the bar struct type has no foobar type.
    has_typedef_foobar<bar>::test<bar>(2.0f);
    has_typedef_foobar<bar>::test<bar>(&one);

    return 0;
}
