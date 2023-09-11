
#include <concepts>
#include <coroutine>
#include <exception>
#include <iostream>

template <typename PromiseType>
class CGetPromise {
    public:
        PromiseType *p_;

        bool await_ready() {
            return false;
        }

        bool await_suspend(std::coroutine_handle<PromiseType> h) {
            p_ = &h.promise();
            return false;
        }

        PromiseType *await_resume() {
            return p_;
        }
};

class CRetObj {
    public:
        struct promise_type {
                int32_t value_;

                CRetObj get_return_object() {
                    return CRetObj{ .h_
                                    = std::coroutine_handle<promise_type>::from_promise(*this) };
                }

                std::suspend_never initial_suspend() {
                    return {};
                }

                std::suspend_never final_suspend() noexcept {
                    return {};
                }

                void unhandled_exception(){};

                std::suspend_always yield_value(int32_t value) {
                    value_ = value;
                    return {};
                }
        };

        std::coroutine_handle<promise_type> h_;

        operator std::coroutine_handle<promise_type>() const {
            return h_;
        }
};

CRetObj counter() {
    for (size_t i = 0;; ++i) {
        co_yield i;  // co yield i => co_await promise.yield_value(i)
    }
}

int main() {
    auto h = counter().h_;
    auto &promise = h.promise();

    for (size_t i = 0; i < 3; ++i) {
        std::cout << "counter: " << promise.value_ << std::endl;
        h();
    }

    h.destroy();
}
