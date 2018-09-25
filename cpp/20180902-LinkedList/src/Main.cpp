#include <iostream>

#ifndef _DEBUG
#define _DEBUG false

#include "LinkedList.h"
#include "Matrix.h"
#include "test.h"
#include <string>


int main(int argc, char* argv[]) {
    /* Linked List test */
    TEST_PRINT(LinkedList test);
    LinkedList<int> l1, l2;
    l1.pushBack(1);
    l1.pushBack(2);
    l1.pushBack(3);
    l1.pushFront(0);
    l1.print();
    l2.pushBack({1,3,5,7,9});
    l2.print();
    LinkedList<char> l3{'3','1','4'};
    l3.print();

    /* Matrix test */
    TEST_PRINT(Matrix test);
    Matrix m1;
    Matrix m2(2, Matrix::ones);
    Matrix m3(3,4, Matrix::eyes);
    Matrix m4(m3);
    Matrix mat1(3, 5, Matrix::ones);
    Matrix mat2(5, 8, Matrix::ones);
    TEST_PRINT(m1);
    m1.display();
    TEST_PRINT(m2);
    m2.display();
    TEST_PRINT(m3);
    m3.display();
    TEST_PRINT(m4);
    m4.display();
    TEST_PRINT(m5 = m4 + m4);
    Matrix m5 = m4.add(m4);
    m5.display();
    TEST_PRINT(m5 transpose);
    m5.transpose().display();
    TEST_PRINT(random matrix);
    m4.generateRandom<>(0, 1).display();
    TEST_PRINT(pointwise scalar multiply);
    m4.pointwiseMultiply(-1.0).display();

    TEST_PRINT(matrix multiplication);
    mat1.product(mat2).display();
    TEST_PRINT(Wrong matrix multiplication);
    try {
        Matrix mat3 = mat2.product(mat1);
        mat3.display();
    } catch (const std::exception& e) {
        std::cerr << e.what();
    }

    return 0;
}

#undef _DEBUG
#endif
