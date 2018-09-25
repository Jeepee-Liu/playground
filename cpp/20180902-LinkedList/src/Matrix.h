#ifndef _MATRIX_H
#define _MATRIX_H 1

#ifndef _DEBUG
#define _DEBUG false
#endif

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <numeric>
#include <string>
#include <exception>
#include <functional>
#include <random>
#include "test.h"

class MatrixException : public std::exception {
    const char* what() const noexcept {
        return "Matrix Exception!\n";
    }
};

class MatrixDimensionException : public MatrixException {
    const char* what() const noexcept {
        return "Matrix Dimension does not match!\n";
    }
};

class Matrix {
public:
    // Type definitions
    typedef double DataT;
    typedef std::vector<DataT> RowT;
    typedef std::vector<RowT> ArrayT;
    typedef std::pair<int, int> MatSizeT;

    enum InitializingT {
        zeros,
        ones,
        eyes
    };

    // Constructors and deconstructors
    Matrix(int m, int n, InitializingT type=zeros); // DONE
    Matrix(int m=3, InitializingT type=zeros) : Matrix(m, m, type) {} // DONE
    Matrix(MatSizeT size, InitializingT type=zeros) :
        Matrix(size.first, size.second, type) {} // DONE
    Matrix(const Matrix& mat); // DONE
    ~Matrix() = default; // DONE

    Matrix& operator= (const Matrix& mat); // NOT TESTED

    inline MatSizeT size() const; // DONE
    void print(std::ostream& os=std::cout) const; // DONE
    void display() const; // DONE

    Matrix& add(const Matrix& mat) const;
    Matrix& substract(const Matrix& mat) const;
    Matrix& pointwiseMultiply(const Matrix& mat) const;
    Matrix& pointwiseDivide(const Matrix& mat) const;

    Matrix& product(const Matrix& mat) const;

    Matrix pointwiseMultiply(DataT& k) const;

    template <class DistT=std::uniform_real_distribution<double>>
    Matrix& generateRandom(double a=0, double b=1) {
        std::random_device rd;
        std::mt19937 gen(rd());
        DistT dist(a, b);
        std::for_each(_data.begin(), _data.end(), [&](RowT& row){
            std::for_each(row.begin(), row.end(), [&](DataT& d){
                d = dist(gen);
            });
        });
        return *this;
    }

    Matrix& transpose();

private:
    int _m = 3;
    int _n = 3;
    ArrayT _data;

    Matrix& pointwiseOperate(const Matrix& mat,
        std::function<DataT(DataT, DataT)> fn) const; // NOT TESTED

    Matrix& pointwiseOperate(std::function<DataT(DataT)> fn) const;

};



#endif // #ifndef _MATRIX_H
