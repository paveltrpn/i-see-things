
// Определена функция с сигнатурой:
// 
// void do_something(bool a, int b, std::string_view c)
// 
// Определить функцию, принимающую в произвольном порядке аргументы типов bool, int, std::string_view и вызывающую 
// функцию do_something с переданными параметрами в качестве аргументов.
// https://habr.com/ru/post/593429/

#include <iostream>
#include <string>
#include <string_view>
#include <tuple>

void do_something(bool a, int b, std::string_view c) {
    std::cout << c;
}

template<typename... Ts>
void wrapper1(Ts&&... args) {
    static_assert(sizeof...(args) == 3, "Invalid number of arguments");

    std::tuple<bool, bool, bool> is_arg_bound;
    std::tuple<bool, int, std::string_view> f_args;

    auto bind_arg = [&](auto &&arg) {
        using arg_type = typename std::remove_reference<decltype(arg)>::type;

        if constexpr (std::is_same<arg_type, bool>::value) {
            std::get<0>(is_arg_bound) = true;
            std::get<0>(f_args) = std::forward<decltype(arg)>(arg);
        } else if constexpr (std::is_same<arg_type, int>::value) {
            std::get<1>(is_arg_bound) = true;
            std::get<1>(f_args) = std::forward<decltype(arg)>(arg);
        } else if constexpr (std::is_same<arg_type, std::string_view>::value) {
            std::get<2>(is_arg_bound) = true;
            std::get<2>(f_args) = std::forward<decltype(arg)>(arg);
        } else {
            static_assert(std::is_void<decltype(arg)>::value, "Invalid argument type");
        }
    };

    (bind_arg(std::forward<decltype(args)>(args)), ...);

    if (!std::apply([](auto... is_arg_bound) { return (is_arg_bound && ...); }, is_arg_bound)) {
        std::cerr << "Invalid arguments" << std::endl;

        return;
    }

    std::apply(do_something, f_args);
}

template<typename R, typename T, typename... Ts>
decltype(auto) get_arg_of_type(T&& arg, Ts&&... args)
{
    using arg_type = typename std::remove_reference<decltype(arg)>::type;

    if constexpr (std::is_same<arg_type, R>::value) {
        return std::forward<T>(arg);
    } else if constexpr (sizeof...(args) > 0) {
        return get_arg_of_type<R>(std::forward<Ts>(args)...);
    } else {
        static_assert(std::is_void<decltype(arg)>::value, "An argument with the specified type was not found");
    }
}

template<typename... Ts>
void wrapper2(Ts&&... args)
{
    static_assert(sizeof...(args) == 3, "Invalid number of arguments");

    do_something(get_arg_of_type<bool>(std::forward<Ts>(args)...),
                 get_arg_of_type<int>(std::forward<Ts>(args)...),
                 get_arg_of_type<std::string>(std::forward<Ts>(args)...));
}

int main(int argc, char **argv) {
    // wrapper1(0, false, "wrapper1()\n");
    wrapper2("wrapper2()\n", 1, true);

    return 0;
}