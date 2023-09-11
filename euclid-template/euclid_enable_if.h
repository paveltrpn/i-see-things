
#ifndef __euclid_enable_if__
#define __euclid_enable_if__

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

template <typename T, typename = std::enable_if<(sizeof(T) == 2)>::type>
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

}  // namespace euclid

#endif
