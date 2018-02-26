#ifndef INCLUDED_MATRIX_
#define INCLUDED_MATRIX_

#include <cstddef>
#include <algorithm>
#include <iostream>

template <size_t Rows, size_t Columns, typename DataType = double>
class Matrix
{
    typedef Matrix<1, Columns, DataType> MatrixRow; 
    typedef Matrix<Rows, 1, DataType> MatrixColumn;
            
    MatrixRow d_matrix[Rows];

    public:     
        Matrix();
       // Matrix(std::istream &str);
        /*
        Matrix(Matrix const &) = default;

        Matrix &operator=(Matrix const &rhs);

    private:
        void swap(Matrix &other);


*/
       // Matrix<1, Columns, DataType> &operator[](size_t idx);
};

template <size_t Rows, size_t Columns, typename DataType> 
inline Matrix<Rows, Columns, DataType>::Matrix()
{
    std::fill(d_matrix, d_matrix + Rows, MatrixRow()); 
}

/*
template <size_t Rows, size_t Columns, typename DataType> 
inline Matrix<Rows, Columns, DataType> &Matrix<Rows, Columns, DataType>::operator=(Matrix<Rows, Columns, DataType> const &other)
{
    Matrix<Rows, Columns, DataType> tmp(other);
    swap(tmp);
    return *this;
}

template <size_t Rows, size_t Columns, typename DataType>
inline void Matrix<size_t Rows, size_t Columns, typename DataType>::swap(Matrix<size_t Rows, size_t Columns, typename DataType> &other)
{
    char tmp[sizeof(Matrix<size_t Rows, size_t Columns, typename DataType>)]; 
    memcpy(tmp, &other, sizeof(Matrix<size_t Rows, size_t Columns, typename DataType>));
    memcpy(&other, this, sizeof(Matrix<size_t Rows, size_t Columns, typename DataType>));
    memcpy(this, tmp, sizeof(Matrix<size_t Rows, size_t Columns, typename DataType>));
}
*/
/*
template <size_t Rows, size_t Columns, typename DataType> 
inline Matrix<Rows, Columns, DataType>::Matrix(std::istream &str) 
{
    for (size_t row = 0; row < Rows; row++)
        for (size_t col = 0; col < Columns; col++)
            str >> d_matrix[row][col];
}

template <size_t Rows, size_t Columns, typename DataType> 
inline Matrix<1, Columns, DataType> &Matrix<Rows, Columns, DataType>::operator[](size_t idx) 
{
    return d_matrix[idx];
}*/

#endif




