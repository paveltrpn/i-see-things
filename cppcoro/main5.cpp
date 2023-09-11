
#include <concepts>
#include <coroutine>
#include <cstdint>
#include <exception>
#include <future>
#include <iostream>

struct resumable {
        struct promise_type;
        std::coroutine_handle<promise_type> h_;
};

struct resumable::promise_type {
        int32_t value_;

        ~promise_type() {
            std::cout << "promise_type destryed" << std::endl;
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

resumable counter() {
    for (int32_t i = 0; i < 3; ++i) {
        co_yield i;
    }

    co_return;
}

int main() {
    resumable coro = counter();
    auto h = coro.h_;
    auto &promise = h.promise();

    while (!h.done()) {
        std::cout << "counter: " << promise.value_ << std::endl;
        h();
    }

    h.destroy();
}
