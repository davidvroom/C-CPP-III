#ifndef INCLUDED_MATRIX_
#define INCLUDED_MATRIX_

#include <cstddef>
#include <algorithm>
#include <iostream>
#include <initializer_list>
#include <cstring> // memcpy

template <typename DataType>
class Matrix
{
                                                   
    template <typename DataType2>                   // opinsert.f
    friend std::ostream &operator<<(std::ostream &out, Matrix<DataType2> const &matrix);
    template <typename DataType2, typename DataType3>                   // opadd1.f
    friend Matrix<DataType2> operator+(Matrix<DataType2> const &lhs, Matrix<DataType3> const &rhs); // 1
    template <typename DataType2, typename DataType3>                   // opadd2.f
    friend Matrix<DataType2> operator+(Matrix<DataType2> &&lhs, Matrix<DataType3> const &rhs);      // 2
    template <typename DataType2, typename DataType3>                   // opequal.f
    friend bool operator==(Matrix<DataType2> const &lhs, Matrix<DataType3> const &rhs);

    size_t d_nRows = 0;
    size_t d_nCols = 0;
    DataType *d_data = 0;  
            
    public:     
        typedef std::initializer_list<std::initializer_list<DataType>> IniList;
        
        Matrix() = default;
        Matrix(size_t nRows, size_t nCols);         // matrix1.f
        Matrix(Matrix const &other);                // matrix2.f
        Matrix(Matrix &&tmp);                       // matrix3.f
        Matrix(IniList inilist);                    // matrix4.f

        ~Matrix();                                  // destructor.f

        template <typename DataType2>
        Matrix &operator=(Matrix<DataType2> const &rhs);       // opassign1.f
        template <typename DataType2>
        Matrix &operator=(Matrix<DataType2> &&tmp);            // opassign2.f

        DataType *operator[](size_t idx);
        DataType const *operator[](size_t idx) const;

        template <typename DataType2>
        Matrix &operator+=(Matrix<DataType2> const &rhs) &;    // opaddis1.f
        template <typename DataType2>
        Matrix &&operator+=(Matrix<DataType2> const &rhs) &&;  // opaddis2.f

        size_t nRows() const;
        size_t nCols() const;
        size_t size() const;

        void swap(Matrix &other);                   // swap.f

    private:
        DataType &el(size_t row, size_t col) const;

        template <typename DataType2>
        void add(Matrix<DataType2> const &rhs);
};

#include "matrix1.f"
#include "matrix2.f"
#include "matrix3.f"
#include "matrix4.f"

#include "destructor.f"

#include "swap.f"
#include "add.f"

#include "opassign1.f"
#include "opassign2.f"
#include "opaddis1.f"
#include "opaddis2.f"
#include "opadd1.f"
#include "opadd2.f"

template <typename DataType>
inline size_t Matrix<DataType>::nCols() const
{
    return d_nCols;
}

template <typename DataType>
inline size_t Matrix<DataType>::nRows() const
{
    return d_nRows;
}

template <typename DataType, typename DataType2>
inline bool operator!=(Matrix<DataType> const &lhs, Matrix<DataType2> const &rhs)
{
    return not (lhs == rhs);
}

template <typename DataType> 
inline size_t Matrix<DataType>::size() const
{
    return d_nRows * d_nCols;
}

template <typename DataType>
inline DataType *Matrix<DataType>::operator[](size_t idx)
{
    return &el(idx, 0);
}

template <typename DataType>
inline DataType const *Matrix<DataType>::operator[](size_t idx) const
{
    return &el(idx, 0);
}

template <typename DataType>
inline DataType &Matrix<DataType>::el(size_t row, size_t col) const
{
    return d_data[row * d_nCols + col];
}

                                                    // free functions
#include "opinsert.f"
#include "opextract.f" 
#include "opequal.f" 

#endif
