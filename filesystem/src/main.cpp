
#include <iostream>
#include <cstdint>
#include <fmt/core.h>

#include "common.h"

/*
int main(int argc, char **argv) {
    fmt::print("{0} {1}", "hello!", "мир\n");

    file_c file;

    try {
        file = file_c("assets/raven.txt");

        std::cout << fmt::format("main(): размер файла {0} - {1} байт.\n", file.getFileName(), file.getFileSize());
    } catch (const exception& e) {
        cout << e.what();
    }

    file.readStrings();

    // file.printAll();
    
    return 0;
}
*/

int main(int argc, char *argv[]) {
    std::cout << fmt::format("{0} {1}", "hello!", "мир\n");
    
    auto [fileContent, fileSize] = readFileToStrVec("assets/raven.txt");

    // auto word_list = splitStringBySepar(fileContent[0], " ");
    // 
    // for (auto& str: word_list) {
        // std::cout << str << std::endl;
    // }
// 
    // std::cout << joinString(" ", word_list);

    auto single_line = joinString(" ", fileContent);
    auto single_line_wp = removePunctuation(single_line);

    std::cout << single_line_wp << std::endl;

    return 0;
}