
#ifndef __smart_ptr_h__
#define __smart_ptr_h__

#include <iostream>
#include <functional>
#include <cstring>
#include <string>

constexpr size_t block = 1024*1024*100; // exactly 100 megabytes

using namespace std;

class houndredMb_c {
    public:
        int8_t *houndredMb;
        static size_t whichOne;

        houndredMb_c() {
            houndredMb = new int8_t[block];
            std::memset(houndredMb, 0, block);
            whichOne = whichOne + 1;

            std::cout << "houndredMb_c(): 100 Mb allocated in " << whichOne << " times!!!\n";
        };

        ~houndredMb_c() {
            delete[] houndredMb;
            
            std::cout << "houndredMb_c(): 100 Mb freed in " << whichOne << " store!!!\n";

            whichOne = whichOne - 1;
        };
};

void shared_ptrAlloc(const std::function<string()> F, size_t countOf);
void unique_ptrAlloc(const std::function<string()> F, size_t countOf);
void weak_ptrAlloc();

#endif