
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "text_read.h"

// Читаем текстовый файл за один раз в строку.
std::string textRead1(std::string fname) {
    std::string textFileString;
    std::ifstream inFile;

    inFile.open(fname, std::ios::in);

    if (!inFile) {
        std::cout << "textRead1(): ERROR! Can't find file " << fname << "\n";
        std::exit(1);
    }

    textFileString.assign(std::istreambuf_iterator<char>(inFile), std::istreambuf_iterator<char>());

    return textFileString;
}

// Читаем текстовый файл за один раз в строку.
std::string textRead2(std::string fname) {
    std::string textFileString;
    std::ifstream inFile;

    inFile.open(fname, std::ios::in); 

    if (!inFile) {
        std::cout << "textRead2(): ERROR! Can't find file " << fname << "\n";
        std::exit(1);
    }
            
    std::stringstream strStream;
    strStream << inFile.rdbuf();

    textFileString = strStream.str();

    return textFileString;
}

// Читаем текстовый файл построчно, возвращаем из функции пару с 
// вектором строк и размером файла.
std::pair<std::vector<std::string>, size_t> textReadToStrVec(std::string fname) {
    std::ifstream file;
    size_t fsize;
    std::string cur_string;
    std::vector<std::string> content;

    file.open(fname, std::ios::in);
    
    if (!file.is_open()) {
        std::cout << "textReadToStrVec(): ERROR! Can't find file " << fname << "\n";
        std::exit(0);
    }

    std::streampos cur_pos = file.tellg();

    file.seekg( 0, std::ios::end );
    fsize = file.tellg() - cur_pos;
    file.seekg( 0, std::ios::beg); 

    while (getline(file,cur_string)) {
        content.push_back(cur_string);
    }
    
    return std::make_pair(content, fsize); 
}

std::string textRead3(std::string fname) {
    std::ifstream inFile;
	std::string rt;

	inFile.open(fname);

	if (!inFile) {
		std::cout << "compileShader(): error! can't open file - " << fname << "\n";
		std::exit(0);
	}

	rt = std::string{std::istreambuf_iterator<char>{inFile}, {}};

    inFile.close();

    return rt;
}
