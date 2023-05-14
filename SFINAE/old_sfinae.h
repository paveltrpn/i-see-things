#ifndef __old_sfinae__
#define __old_sfinae__

#include <format>
#include <iostream>

template <typename T> struct has_typedef_foobar {
        typedef char yes[2];
        typedef char no[1];
        template <typename C> static yes& test(typename C::foobar* foo) {
            std::cout << "called yes& test(typename C::foobar* foo)\n";

            yes rt = { 0, 1 };
            return rt;
        };

        template <typename> static no& test(...) {
            std::cout << "called no& test(...)\n";

            no rt;
            return rt;
        };

        static const bool value;
};

#endif
