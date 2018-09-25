#ifndef _TEST_H
#define _TEST_H 1

#include <iostream>

#define TEST_PRINT(x) std::cout << "==== " << #x \
        << " ===="<< std::endl
#define TEST_VAR(x) std::cout << #x << " = " << x << std::endl

#endif
