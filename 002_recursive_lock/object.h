
#ifndef __object_h__
#define __object_h__

#include <mutex>
#include <string>
#include <vector>

struct RecObject {
        RecObject();
        ~RecObject();

        void callLock(const std::string &arg);

        void secondCall();

    private:
        std::mutex m_mutex;

        double m_someThing = 10.0;
        double m_result;

        std::vector<std::string> m_storage;
};

#endif
