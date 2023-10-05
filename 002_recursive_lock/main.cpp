
//
// Single process deadlock example.
//

#include <iostream>
#include <format>

#include "object.h"

int main(int argc, char **argv) {
    std::cout << "begin\n";

    RecObject foo;
    
    // take lock, push to vector and release
    foo.callLock("some");

    // take lock, print vector containment and call foo.callLock() which
    // try to lock same mutex - m_mutex, result - deadlock
    // in debug we can see mutex state with _lock = 2 member value 
    foo.secondCall();

    return 0;
}
