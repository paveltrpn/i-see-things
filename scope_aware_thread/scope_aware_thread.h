
#ifndef __scope_aware_thread__
#define __scope_aware_thread__

#include <iostream>
#include <thread>

class thread_guard_c {
    public:
        explicit thread_guard_c(std::thread &t) : t_{ t } {};

        ~thread_guard_c() {
            if (t_.joinable()) {
                t_.join();
            }
        };

        thread_guard_c(thread_guard_c const &) = delete;
        thread_guard_c &operator=(thread_guard_c const &) = delete;
        thread_guard_c &operator=(const thread_guard_c &&) = delete;

    private:
        std::thread &t_;
};

// scoped aware thread wrapper
class sathread_c {
    public:
        explicit sathread_c(std::thread t) : t_{ std::move(t) } {
            if (!t_.joinable()) {
                throw std::logic_error("No thread");
            }
        };

        ~sathread_c() {
            t_.join();
        };

        sathread_c(sathread_c const &) = delete;
        sathread_c &operator=(sathread_c const &) = delete;
        sathread_c &operator=(const sathread_c &&) = delete;

    private:
        std::thread t_;
};

#endif
