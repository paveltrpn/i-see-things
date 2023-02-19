

#include "common.h"

file_c::file_c() {
    fname = "";
    fsize = 0;
};

file_c::file_c(string name) {
    fname = name;

    file.open(fname, ios::in);
    
    if (!file) {
        throw std::runtime_error("file_c(): can't open file - " + fname + "!!!\n");
    }

    std::streampos cur_pos = file.tellg();

    file.seekg( 0, std::ios::end );
    fsize = file.tellg() - cur_pos;
    file.seekg( 0, std::ios::beg);
};

file_c & file_c::operator=(file_c &&fc) {
    fname = fc.fname;
    fsize = fc.fsize;
    file = move(fc.file);

    content = fc.content;
    fc.fname = "";
    fc.fsize = 0;

    fc.content.clear();
    return *this;
};

file_c::~file_c() {
    file.close();
};

void file_c::readStrings() {
    string cur_string;

    while (getline(file,cur_string)) {
        content.push_back(cur_string);
    }
}

size_t file_c::getFileSize() {
    return fsize;
}

string file_c::getFileName() {
    return fname;
}

void file_c::printAll() {
    if (!content.empty()) {
        for (const string &str: content) {
            cout << str << "\n";
        }
    } else {
        fmt::print("file_c::printAll(): файл {0} открыт но не прчитан.\n", fname);
    }
}

std::pair<std::vector<std::string>, size_t> readFileToStrVec(std::string fname) {
    std::ifstream file;
    size_t fsize;
    std::string cur_string;
    std::vector<std::string> content;

    file.open(fname, ios::in);
    
    if (!file.is_open()) {
        std::cout << fmt::format("readFileToStrVec(): can't open file {0}!\n", fname);
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
