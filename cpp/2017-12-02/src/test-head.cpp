#include "test-head.h"
#ifdef TEST_HEAD_H

std::optional<std::string> sayHello(bool b) {
    return b ? std::optional<std::string>("Hello") : std::nullopt;
}

#endif
