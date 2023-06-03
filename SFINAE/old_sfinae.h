#ifndef __old_sfinae__
#define __old_sfinae__

#include <format>
#include <iostream>
#include <memory>
#include <cstdint>

template <typename T> struct has_typedef_foobar {
        typedef char yes[2];
        typedef char no[1];
        // Why "typename" in argumens list??? Disambiguiation???
        template <typename C> static yes& test(typename C::foobar* foo) {
            // print passed address, because of why not?)))
            std::cout << std::format("called \"yes& test(typename C::faoobar* foo)\" - {:x}\n", 
                    reinterpret_cast<int64_t>(foo));
            
            yes rt = { 0, 1 };
            return rt;
        };

        // Why "typename" with empty type in template???
        template <typename> static no& test(...) {
            std::cout << std::format("called \"no& test(...)\"\n");

            no rt;
            return rt;
        };

        static const bool value;
};

#endif
