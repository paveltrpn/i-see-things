
#include <concepts>
#include <coroutine>
#include <cstdint>
#include <exception>
#include <iostream>
#include <format>

struct resumable {
    struct promise_type {
        int32_t value_;

        ~promise_type() {
            std::cout << "promise_type destroyed" << std::endl;
        }

        resumable get_return_object() {
            return { .h_ = std::coroutine_handle<promise_type>::from_promise(*this) };
        }

        std::suspend_never initial_suspend() {
            return {};
        }

        std::suspend_always final_suspend() noexcept {
            return {};
        }

        void unhandled_exception() {
        }

        std::suspend_always yield_value(int32_t value) {
            value_ = value;
            return {};
        }

        void return_void() {
        }
    };

    std::coroutine_handle<promise_type> h_;

    auto operator()() {
        h_();
        return h_.promise().value_;
    }

    bool isDone() {
        return h_.done();
    }

    ~resumable() {
        h_.destroy();
    }
};



resumable counter() {
    for (int32_t i = 0; i < 3; ++i) {
        co_yield i;
    }

    //co_return;
}

int main() {
    resumable coro = counter();

    //while (!coro.isDone()) {
    //    std::cout << "counter: " << coro() << std::endl;
    //}

    for (size_t i = 0; i < 4; ++i) {
        std::cout << std::format("is done - {}, counter - {}\n", coro.isDone(), coro());
    }
}
