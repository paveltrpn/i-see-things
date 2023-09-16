
#ifndef __euclid_enable_if__
#define __euclid_enable_if__

#include <cstddef>
#include <iostream>
#include <type_traits>

#include "local_math.h"

namespace euclid {

template <typename T, typename = std::enable_if<std::is_integral<T>::value, T>::type>
struct GcdFunctorEnif {
        T operator()(T a, T b) {
            auto max = std::max(a, b);
            auto min = std::min(a, b);

            auto frac = euclidMod<T>(max, min);

            while (frac != 0) {
                max = min;
                min = frac;
                frac = euclidMod(max, min);
            }

            return min;
        };
};

template <typename T, typename = std::enable_if<(sizeof(T) == 2), int>::type>
T funcByteOperate(T arg) {
    T vv{ 127 };
    return arg * vv;
}

template <typename T, typename = std::enable_if_t<(sizeof(T) == 2)>>
T funcByteOperateAnother(T arg) {
    T vv{ 127 };
    return arg * vv;
}

template <typename T, typename = std::enable_if<(sizeof(T) == 2)>::type>
T funcByteOperateAnotherOther(T arg) {
    T vv{ 127 };
    return arg * vv;
}

template <size_t n>
struct square : std::integral_constant<size_t, n * n> {};

static void fromFunctor() {
    auto v = square<10>::value; // v = 100
}

}  // namespace euclid

#endif
