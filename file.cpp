
#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>
#include <functional>

#include "hints.h"

//  Читаем из бинарного файла n-байт 
int read_binary_n_bytes(std::string fname, std::size_t size) {
    std::ifstream fp(fname, std::ifstream::binary);
    //   или так 
    //   std::unique_ptr<char[]> buffer(new char[size]);
    std::unique_ptr<char[]> buffer = std::make_unique<char[]>(size);
    std::size_t file_size;
    
    if (!fp.is_open()) {
        std::cout << "read_binary_n_bytes(): error opening file '" << fname << "." << std::endl;
        return 1;
    }

    //    Определяем размер файла. Ставим каретку в конец файла, 
    //    получаем позицию каретки в конкретном filestram и
    //    возвращаемся в начало */
    fp.seekg(0,std::ios_base::end);
    file_size = static_cast<uint32_t>(fp.tellg());
    fp.seekg(0,std::ios_base::beg);

    if (file_size < size) {
        std::cout << "read_binary_n_bytes(): error, trying to read too many bytes!" << std::endl;
        fp.close();
        return 1;
    }
    //   reinterpret_cast<typ>(expr) - позволяет преобразовывать любой указатель в указатель любого другого типа. 
    //   Также позволяет преобразовывать любой целочисленный тип в любой тип указателя и наоборот.
    fp.read(reinterpret_cast<char*>(&buffer), size);

    fp.close();

    return 0;
}

int read_file_by_string(std::string fname) {
    std::ifstream fp;
    std::vector<std::string> in_file;
    std::string cur_string;
    // float b{10.0}; // brace initialization
    
    fp.open(fname);
    if (!fp.is_open()) {
        std::cout << "read_file_by_string(): error opening file " << fname << "." << std::endl;
        return 1;
    }

    //   std::getline cчитывает неформатированные данные из потока в строку. 
    //   Останавливается, как только найден символ, равный разделителю, или исчерпан поток. 
    //   Первая версия использует в качестве разделителя delim, вторая — '\n'. 
    //   Символ-разделитель удаляется из потока и не помещается в строку. 
    for (;std::getline(fp,cur_string);) {
        /* Добавляем её в выходной вектор */
        in_file.push_back(cur_string);
    }

    //   Лябда функция, замыкающая внешнюю переменную in_file по ссылке,
    //   принимающая один аргумент n типа int и возвращающая значение
    //   типа int. 
    auto test = [&in_file] (int n) -> int {
        for (auto &str : in_file) {
            std::cout << n++ << " " << str << std::endl;
        }

        return n;
    } (0); //   круглые скобки в конце - вызов лямбды

    // такая же лямбда как и выше, по другому объявленная, результат тот же 
    auto test_second {
        [&in_file] (int n) -> int {
            for (auto &str : in_file) {
                std::cout << n++ << " " << str << std::endl;
            }

            return n;
        } /* (0) - в этом месте вызовет лямбду */
    };
    test_second(1); // вызвали ранее объявленную лямбду

    fp.close();

    return 0;
}

int file_test() {
    std::cout << "TEST - file.cpp" << "\n" << std::endl;

    read_file_by_string("/home/pavel/code/cpp_trivia/hints/hints.h");
    
    return 0;
}