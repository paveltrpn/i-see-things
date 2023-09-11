#ifndef __old_sfinae__
#define __old_sfinae__

template <typename T>
struct has_typedef_foobar {
        using yes = char[2];
        using no = char[1];
        // Why "typename" in argumens list??? Disambiguiation???
        template <typename C>
        static yes& test(typename C::foobar* foo){};
        // Why "typename" with empty type in template???
        template <typename>
        static no& test(...){};
        static const bool value;
};

#endif
