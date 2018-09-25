#include "Matrix.h"
#ifdef _MATRIX_H

/* In Matrix */
// typedef double DataT;
// typedef std::vector<std::vector<DataT>> ArrayT;

Matrix::Matrix(int m, int n, InitializingT type) : _m(m), _n(n),
    _data(ArrayT(m, RowT(n, type == ones ? 1 : 0))) {
    if(type == eyes)
        for(int i = 0; i < std::min(_m, _n); ++i)
            _data[i][i] = 1;
}

Matrix::Matrix(const Matrix& mat) : Matrix(mat.size(), zeros) {
    for(int i = 0; i < _m; ++i) {
        for(int j = 0; j < _n; ++j) {
            _data[i][j] = mat._data[i][j];
        }
    }
}

Matrix& Matrix::operator= (const Matrix& mat) {
    if(size() != mat.size()) {
        _data = ArrayT(mat._m, RowT(mat._n, 0));
        _m = mat._m;
        _n = mat._n;
    }
    for(int i = 0; i < _m; ++i) {
        for(int j = 0; j < _n; ++j) {
            _data[i][j] = mat._data[i][j];
        }
    }
    return *this;
}

inline Matrix::MatSizeT Matrix::size() const {
    return std::pair<int, int>(_m, _n);
}

void Matrix::print(std::ostream& os) const {
    std::for_each(_data.begin(), _data.end(), [&os](RowT row){
        os << std::accumulate(row.begin() + 1, row.end(),
            row.empty() ? "" : std::to_string(row[0]),
            [](std::string s, DataT d){ return s + " " + std::to_string(d); });
        os << std::endl;
    });
}

void Matrix::display() const {
    std::cout << "[ " << _m << " by " << _n << " matrix ]:\n";
    print(std::cout);
}

Matrix& Matrix::add(const Matrix& mat) const {
    return pointwiseOperate(mat, std::plus<DataT>());
}

Matrix& Matrix::substract(const Matrix& mat) const {
    return pointwiseOperate(mat, std::minus<DataT>());
}

Matrix& Matrix::pointwiseMultiply(const Matrix& mat) const {
    return pointwiseOperate(mat, std::multiplies<DataT>());
}

Matrix& Matrix::pointwiseDivide(const Matrix& mat) const {
    return pointwiseOperate(mat, std::divides<DataT>());
}

Matrix& Matrix::product(const Matrix& mat) const {
    if(_n != mat._m) throw MatrixDimensionException();
    Matrix* pNewMat = new Matrix(_m, mat._n, zeros);
    for(int m = 0; m < _m; ++m)
        for(int n = 0; n < mat._n; ++n)
            for(int i = 0; i < _n; ++i)
                pNewMat->_data[m][n] +=
                    _data[m][i] * mat._data[i][n];
    return *pNewMat;
}

Matrix Matrix::pointwiseMultiply(DataT& k) const {
    return pointwiseOperate([&k](int x){ return x*k; });
}

Matrix& Matrix::transpose() {
    ArrayT newData(_n, RowT(_m, 0));
    for(int i = 0; i < _m; ++i)
        for(int j = 0; j < _n; ++j)
            newData[j][i] = _data[i][j];
    _data = newData;
    std::swap(_m, _n);
    return *this;
}

Matrix& Matrix::pointwiseOperate(const Matrix& mat,
    std::function<DataT(DataT, DataT)> fn) const {
    if(size() != mat.size()) throw MatrixDimensionException();
    Matrix* pNewMat = new Matrix(mat);
    for(int i = 0; i < _m; ++i)
        for(int j = 0; j < _m; ++j)
            pNewMat->_data[i][j] = fn(_data[i][j], pNewMat->_data[i][j]);
    return *pNewMat;
}

Matrix& Matrix::pointwiseOperate(std::function<DataT(DataT)> fn) const {
    Matrix* pNewMat = new Matrix(*this);
    for(int i = 0; i < _m; ++i)
        for(int j = 0; j < _m; ++j)
            pNewMat->_data[i][j] = fn(_data[i][j]);
    return *pNewMat;
}

#endif
