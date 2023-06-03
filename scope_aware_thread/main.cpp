
#include <iostream>
#include <thread>
#include <format>
#include <string>

#include "scope_aware_thread.h"

struct functor_s {
    std::string message;

    functor_s(std::string m): message{m} {};

    void operator()() {
        std::cout << std::format("functor done with message - {}\n", message);
    };
};

void worker(const std::string &msg) {
    std::cout << std::format("worker done with message - {}!\n", msg);
}

int main(int argc, char *argv[]) {
    std::thread foo{worker, "i'm guarded!"};
    thread_guard_c guard{foo};

    std::string msg = "i'm scoped!";
    functor_s fworker{"i'm scoped!"};

    sathread_c foo2{std::thread{fworker}};

    std::cout << std::format("main work...\n");

    return 0;
}
