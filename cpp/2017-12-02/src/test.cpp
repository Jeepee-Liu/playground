#include "test.h"
#ifdef TEST_H

int main () {
    std::cout << "Test c++1z" << std::endl;
    std::cout << "Sum: " << sum(1,2,3,4,5) << std::endl;
    std::cout << "Product: " << prod(1,2,3,4,5) << std::endl;
    std::cout << "Print: ";
    printAll(1,2,3,4,5);
    std::cout << "Optional hello:\n\t[ b =  true ] " << *sayHello(true)
    << "\n\t[ b = false ] " << sayHello(false).value_or("NULL")
    << std::endl;

    // Fuzzy logic test
    Fuzzy fz1;
    Fuzzy fz2(fz1);
    Fuzzy fz3(0.1);
    Fuzzy fz4(0.9);
    Fuzzy fz5 = fz3.fzAND(fz4);
    // std::cout << "Out of function: " << fz5 << '\t'
    // << &fz5 << std::endl;
    Fuzzy fz6 = fz3.fzOR(fz4);
    std::cout << "fz1 = " << fz1
    << "\nfz2 = " << fz2
    << "\nfz3 = " << fz3
    << "\nfz4 = " << fz4
    << "\nfz3 AND fz4 = " << fz5
    << "\nfz3 OR fz4 = " << fz6
    << "\nNOT (fz3 OR fz4) = " << fz6.fzNOT()
    << "\n1.0 XOR 0.0 = " << Fuzzy(1.).fzXOR(Fuzzy(0.))
    << "\n0.8 XOR 0.7 = " << Fuzzy(0.8).fzXOR(Fuzzy(0.7))
    << "\nState of 0.8: " << Fuzzy(0.8).getState()
    << "\nState of 0.5: " << Fuzzy(0.5  ).getState()
    << "\nState of 0.2: " << Fuzzy(0.2).getState() << std::endl;
    return 0;
}

#endif
