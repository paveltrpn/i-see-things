
#include <memory>
#include <iostream>
#include <functional>
#include <string>

#include "smart_ptr.h"

using namespace std;

void shared_ptrAlloc(const std::function<string()> F, size_t countOf) {
    // Note that you can't use a shared pointer the same way as a pointer you'd get from new[], 
    // because std::shared_ptr (unlike std::unique_ptr, for example) does not provide operator[]. 
    // You'd have to dereference it: (*buffer)[n] = 'a';
    // Отсюда - https://stackoverflow.com/questions/13794447/can-you-allocate-an-array-with-something-equivalent-to-make-shared

    // Не получается выделить массив объектов с помощью make_shared(),
    // компилятор выдаёт здоровый непонятный трейс
    
    // auto foo = std::make_shared<houndredMb_c[]>(countOf);

    // А вот кнструктором выделить можно.
    
    auto foo = shared_ptr<houndredMb_c[]>(new houndredMb_c[countOf]);

    while (true) {
        string word = F();

        if (word == "quit") {
            break;
        }

        if (word == "reset") {
            foo.reset();
            cout << "shared_ptrAlloc(): accept reset command! Free all objects!\n";
        }

        if (word == "realloc") {
            // Если указатель не освобождён от объектов
            // то будут вызваны конструкторы новых объектов, выделена память, а
            // предыдущие объекты освобождены
            foo = shared_ptr<houndredMb_c[]>(new houndredMb_c[countOf]);
        }

        if (word == "use_count") {
            cout << "shared_ptrAlloc(): foo.use_count=" << foo.use_count() << "\n";
        }

        if (word == "check") {
            if (foo) {
                cout << "shared_ptrAlloc(): *foo=" << foo << "\n";
                cout << "shared_ptrAlloc(): sizeof(foo)=" << sizeof(foo) << "\n";
            } else {
                cout << "shared_ptrAlloc(): foo is not a valid pointer.\n";
            }
        }
    };
}

void unique_ptrAlloc(const std::function<string()> F, size_t countOf) {
    // Можно и через конструктор и через make_unique<>(), результат одинаковый.

    // auto foo = unique_ptr<houndredMb_c[]>(new houndredMb_c[countOf]);
    auto foo = make_unique<houndredMb_c[]>(countOf);

    while (true) {
        string word = F();

        if (word == "quit") {
            break;
        }

        if (word == "reset") {
            foo.reset();
            cout << "unique_ptrAlloc(): accept reset command! Free all objects!\n";
        }
    };
}

void weak_ptrAlloc() {

}
