
#include <cstdint>
#include <iostream>
#include <concepts>
#include <coroutine>

#include <exception>
class CRetObj {
    public:
        class promise_type {
            public:
                int32_t value_;

                ~promise_type() {
                    std::cout << "promise_type destryed" << std::endl;
                }

                CRetObj get_return_object() {
                    return {
                        .h_ = std::coroutine_handle<promise_type>::from_promise(*this)
                    };
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
};

CRetObj counter() {
    for (int32_t i = 0; i < 3; ++i) {
        co_yield i;
    }

    co_return;
}

int main() {
    auto h = counter().h_;
    auto &promise = h.promise();
    while (!h.done()) {
        std::cout << "counter: " << promise.value_ << std:: endl;
        h();
    }
    h.destroy();
}
