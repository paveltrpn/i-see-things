
#ifndef __common_h__
#define __common_h__

#include <iostream>
#include <functional>
#include <cstring>
#include <string>
#include <memory>

constexpr size_t block = 1024*1024*1024; // exactly one gigabyte

using namespace std;

class oneGb_c {
    public:
        unique_ptr<int8_t[]> oneGb;
        string myName;

        oneGb_c() {
            oneGb = unique_ptr<int8_t[]>(new int8_t[block]);
            std::memset(oneGb.get(), 0, block);
            myName = "default";

            std::cout << "oneGb_c(): 100 Mb allocated in " << myName << " place!!!\n";
        };

        oneGb_c(string name) {
            oneGb = unique_ptr<int8_t[]>(new int8_t[block]);
            std::memset(oneGb.get(), 0, block);
            myName = name;

            std::cout << "oneGb_c(): 100 Mb allocated in " << myName << " place!!!\n";
        };

        // конструктор перемещения
        oneGb_c(string name, oneGb_c&& from) {
            myName = name;

            cout << "oneGb_c(): one gigabyte moved from " << from.myName << " to " << "name " << name << "\n";
            oneGb = move(from.oneGb);
        }

        // Оператор перемещения
        oneGb_c& operator=(oneGb_c&& from) {
            oneGb = std::move(from.oneGb);

            // Возвращаем текущий объект, чтобы иметь возможность связать в цепочку выполнение нескольких операций присваивания
            return *this;
        };

        ~oneGb_c() {
            std::cout << "oneGb_c(): 100 Mb freed in " << myName << " place!!!\n";
        };
};

void refrefTest();

#endif
