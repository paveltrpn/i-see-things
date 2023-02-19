
#include <iostream>
#include <cmath>

// Работает для любого целочисленного аргумента
template <typename T, std::enable_if_t<std::is_integral_v<T>, int> = 0>
bool isPowerOfTwo(T arg) {
    return arg > 0 && (arg & (arg - 1)) == 0;
}

// Работает для аргумента типа с плавающей точкой
template <typename T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
bool isPowerOfTwo(T arg) {
    int exponent;

    const T mantissa = std::frexp(arg, &exponent);

    return mantissa == T(0.5);
}

int main(int argc, char **argv) {
    std::cout << isPowerOfTwo(2) << "\n";
    std::cout << isPowerOfTwo(3) << "\n";
    std::cout << isPowerOfTwo(6.56) << "\n";
    std::cout << isPowerOfTwo(8.00) << "\n";

    return 0;
}