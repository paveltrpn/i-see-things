
#include <iostream>
#include <format>

#include "euclid.h"
#include "euclid_enable_if.h"

int main(int argc, char **argv) {
    auto foo = euclid::GcdFunctor<int>{};
    auto _ = euclid::GcdFunctorEnif<int>{};

#ifdef ERROR_CASE
    auto _ = euclid::GcdFunctorEnif<float>{};  // error
#endif

    std::cout << std::format("GcdFunctor = {}\n", foo(14, -8));

    std::cout << std::format("byte operate = {}\n", euclid::funcByteOperate<short>(1));
    std::cout << std::format("byte operate another other = {}\n",
                             euclid::funcByteOperateAnotherOther<short>(1));

    return 0;
}
