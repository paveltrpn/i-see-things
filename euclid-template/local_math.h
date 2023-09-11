
#ifndef __local_math_h__
#define __local_math_h__

namespace euclid {

template<typename T>
T abs(T a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

template<typename T>
T euclidMod(T a, T b) {
    T rt;

    // static_assert(b != 0);

    rt = a % b;

    if (rt < 0) {
        rt += abs(b);
    }

    return rt;
}

}

#endif
