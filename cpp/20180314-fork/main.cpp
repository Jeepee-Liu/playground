// Copyright

#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <unistd.h>
#include <functional>
#include <string>
#include <any>
#include <typeinfo>

std::mutex coutLock;
typedef std::vector<std::any> AnyVector;

template <typename T>
void count(const T& threadName) {
    for (int i = 0; i < 5; ++i) {
        coutLock.lock();
        std::cout << "[ " << threadName << " ] Counting : "
        << i << std::endl;
        coutLock.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void anyTest() {
    AnyVector anyVector;
    anyVector.push_back(3.5);
    anyVector.push_back(1000);
    anyVector.push_back(999999999L);
    anyVector.push_back("What's this?");
    anyVector.push_back('0');
    anyVector.push_back(3.5);
    try {
        for (auto item : anyVector) {
            auto type = item.type();
            std::cout << std::any_cast<type>(item) << std::endl;
        }
    } catch (const std::bad_any_cast& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main(int argc, char const *argv[]) {
    // Using thread
    std::cout << "Multi-threading using \"std::thread\"" << std::endl;
    auto count1 = std::bind(count<std::string>, "Thread 1");
    auto count2 = std::bind(count<std::string>, "Thread 2");
    std::thread t1(count1);
    std::thread t2(count2);
    t1.join();
    t2.join();

    anyTest();

    // Using fork()
    /**
    std::cout << "Multi-threading using `fork()`" << std::endl;
    pid_t pid = fork();
    if(pid==0) {
        count("Parent thread");
    } else if (pid > 0) {
        count("Child Thread");
    } else {
        std::cout << "Fork failed!" << std::endl;
        return 1;
    }
     */
    return 0;
}
