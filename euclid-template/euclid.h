
#ifndef __euclid_h__
#define __euclid_h__

#include <iostream>

#include "local_math.h"

namespace euclid {

template <typename T>
struct GcdFunctor {
    T operator() (T a, T b) {
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

}

#endif
