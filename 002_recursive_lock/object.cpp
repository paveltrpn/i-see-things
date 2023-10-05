
#include "object.h"
#include <mutex>
#include <iostream>
#include <format>

RecObject::RecObject() {
    m_storage.emplace_back("first");
    m_storage.emplace_back("secont");
}

RecObject::~RecObject() = default;

void RecObject::callLock(const std::string &arg) {
    std::lock_guard lock{ m_mutex };

    m_storage.emplace_back(arg);
}

void RecObject::secondCall() {
    std::cout << "secondCall() before lock\n";

    std::lock_guard lock{m_mutex};

    for (auto & msg: m_storage) {
        std::cout << std::format("{}\n", msg);
    }

    callLock("fourth");
}
