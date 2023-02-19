
#include <iostream>
#include "smart_ptr.h"

using namespace std;

size_t houndredMb_c::whichOne = 0;

int main(int argc, char *argv[]) {

    unique_ptrAlloc([]() -> string { 
                            string word;
                            cout << "unique_ptrAlloc(): wait for input...!!!\n";
                            cin >> word;
                            return word;
                        }, 5);

    // shared_ptrAlloc([]() -> string { 
    //                         string word;
    //                         cout << "shared_ptrAlloc(): wait for input... (quit for exit)\n";
    //                         cin >> word;
    //                         return word;
    //                     }, 5);

    return 0;
}