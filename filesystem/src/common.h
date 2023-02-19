
#ifndef __common_h__
#define __common_h__

#include <iostream>
#include <fstream>
#include <vector>
#include <fmt/core.h>
#include <utility>

using namespace std;

class file_c
{
    private:
        string fname;
        fstream file;
        size_t fsize;
        vector<string> content;

        file_c(file_c &fc) = delete;
        file_c(file_c &&fc) = delete;
        file_c &operator=(file_c &fc) = delete;

    public:

        // file_c(const file_c &fc) {
            // 
        // };
        // 
        // file_c(file_c && fc): file_c() {
            // *this = static_cast<file_c&&>(fc);
        // }
        // 
        // file_c &operator=(const file_c &fc) {
            // return *this = file_c(fc);
        // }

        file_c();
        file_c(string name);

        file_c &operator=(file_c &&fc);

        ~file_c();

        void readStrings();
        size_t getFileSize();
        string getFileName();
        void printAll();
};

std::pair<std::vector<std::string>, size_t> 
readFileToStrVec(std::string fname);

std::vector<std::string> 
splitStringBySepar(const std::string &string, const char * sep);

std::string
joinString(const char * delimiter, std::vector<std::string> const& inputs);

std::string 
removePunctuation(const std::string& str);

#endif