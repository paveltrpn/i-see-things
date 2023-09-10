
#include <iostream>
#include <format>

template<typename T, typename U>
struct FooOne {
    T tType;
    U utype;

    using type = T;

    int intField = 100;
    
    static bool value;
    static T _tDef;

    FooOne(int f): intField{f} {}

    static bool getValue() {
        return value;
    };
};

template<typename C, typename V>
C FooOne<C, V>::_tDef = 100;

//template<typename T>
//T FooOne<T, float>::_tDef = 100.f;

template<>
int FooOne<int, int>::_tDef = 100;

template<typename C, typename V>
bool FooOne<C, V>::value = false;

template<>
bool FooOne<int, int>::value = true;

static inline void foobar() {
    using tt = typename FooOne<int, int>::type;    
    auto bb = FooOne<int, int>::value;
    auto ff = FooOne<float, float>::_tDef;

    std::cout << std::format("{} {}\n", bb, ff);
}
