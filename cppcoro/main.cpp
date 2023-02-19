
#include <iostream>
#include <concepts>
#include <coroutine>
#include <exception>

class CRetObj {
    public:
        class promise_type {
            public:
                CRetObj get_return_object() {
                    return {};
                }
                
                std::suspend_never initial_suspend() {
                    return {};
                }
                
                std::suspend_never final_suspend() noexcept {
                    return {};
                }

                void unhandled_exception() const noexcept {

                }
        };
};

struct CAwaiter {
    std::coroutine_handle<> *hp_;

    constexpr bool await_ready() const noexcept {
        return false;
    }

    void await_suspend(std::coroutine_handle<> h) {
        *hp_ = h;
    }

    constexpr void await_resume() const noexcept {
    }

    public:
        CAwaiter(std::coroutine_handle<> *h) {
            hp_ = h;
        }
};

CRetObj counter(std::coroutine_handle<> *continuation_out) {
    CAwaiter a{continuation_out};

    for (int32_t i = 0; ; ++i) {
        co_await a;
        std::cout << "counter: " << i << std::endl;
    }
}

int main() {
    std::coroutine_handle<> h;

    counter(&h);

    for (int32_t i = 0; i < 3; i++) {
        std::cout << "loop: " << i << "\n";
        h();
    }

    h.destroy();

    return 0;
}
