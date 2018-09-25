#ifndef TEST_HEAD_H
#define TEST_HEAD_H

#include <iostream>
#include <string>
#include <optional>

template <typename... T>
auto sum(T... args) {
    return (args + ...);
}

template <typename... T>
auto prod(T... args) {
    return (args * ...);
}

template <typename... T>
void printAll(T... args) {
    (std::cout << ... << args) << std::endl;
}

std::optional<std::string> sayHello(bool b);

#endif
