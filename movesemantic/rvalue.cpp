
#include <vector>

#include "common.h"

// Простой пример работы forward и move

// std::string gstr;

// template<typename T>
// void g(T arg) {
//     gstr = std::move(arg);
// }

// template<typename T>
// void f(T&& arg) {
//     g(std::move(arg));
// }

// int main() {
//     std::string str { "test" };
//     f(str);
//     return 0;
// }

// После выполнения f(str) строка "test" перемещается в gstr, чего программист, 
// вероятно, не ожидал. Но вот если вызов g записать как g(std::forward<T>(arg)), 
// то функция forward распознает аргумент arg как lvalue и строка корректно скопируется.

void refrefConcept(const auto& inParam) {
    std::cout << "refrefConcept() call.\n";

    for (auto&& i: inParam) {
        std::cout << i << " ";
    }

    std::cout << "\n";
}

template <typename T>
void refrefConceptOld(T inParam) {
    std::cout << "refrefConceptOld() call.\n";

    for (auto&& i: inParam) {
        std::cout << i << " ";
    }

    std::cout << "\n";
}

template <typename T>
void refrefTemplate(T&& inParam) {
    std::cout << "refrefTemplate() call.\n";

    for (auto&& i: inParam) {
        std::cout << i << " ";
    }

    std::cout << "\n";
}

void refrefFunc(const std::vector<int>& inParam) {
    std::cout << "refrefFunc() call.\n";
    for (auto& i: inParam) {
        std::cout << i << " ";
    }

    std::cout << "\n";
}

void refrefTest() {
    std::vector<int> bar{0, 1, 2, 3, 4, 5};

    // Несмотря на то, что здесь используется именно мув, вектор не перемещается
    refrefTemplate(std::move(bar));
    // Щас после вызова refrefConcept(std::move(bar)); для bar будет вызван конструктор перемещения
    // если убрать мув то bar не переместится
    refrefConceptOld(std::move(bar));
    refrefFunc(bar);

    for (auto& i: bar) {
        std::cout << i << " ";
    }

    std::cout << "\n";
}
