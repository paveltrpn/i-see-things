
#include <iostream>
#include <concepts>
#include <coroutine>
#include <exception>

class CRetObj {
    public:
        class promise_type {
            public:
                CRetObj get_return_object() {
                    return {
                        .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
                    };
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

        std::coroutine_handle<promise_type> h_;

            operator std::coroutine_handle<promise_type>() const {
                return h_;
            }

            operator std::coroutine_handle<>() const {
                return h_;
            }
};

CRetObj counter() {
    for (size_t i = 0;; ++i) {
        co_await std::suspend_always{};
        std::cout << "counter: " << i << std::endl;
    }
}

int main() {
    std::coroutine_handle<> h = counter();
    for (size_t i = 0; i < 3; ++i) {
        std::cout << "In main()\n";
        h();
    }
}