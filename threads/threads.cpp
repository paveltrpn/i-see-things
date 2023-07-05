
#include <iostream>
#include <format>
#include <thread>
#include <future>

void test_simple_thread() {
    int result{};

    auto work = [&result](int a, int b) {
        result = a + b;
    };

    std::thread worker {work, 1, 1};
    worker.join();

    std::cout << std::format("test_simple_worker()\nresult = {}\n", result);
}

// std::promise + std::future mechanism
void test_async_worker() {
    std::promise<int> prms;
    std::future<int> ftr = prms.get_future();

    auto foo = [](std::promise<int>&& result, int a, int b) {
        result.set_value(a + b);
    };
    
    std::thread worker{foo, std::move(prms), 10, 11};
    worker.detach();

    std::cout << std::format("test_async_worker()\nresult = {}\n", ftr.get());
}

void test_async_task() {

}

int main(int argc, char *argv[]) {
    test_simple_thread();
    test_async_worker();
    return 0;
}
