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
    size_t d_nRows = 0;
    size_t d_nCols = 0;
    DataType *d_data = 0;  
            
    public:     
        typedef std::initializer_list<std::initializer_list<DataType>> IniList;
        
        Matrix() = default;
        Matrix(size_t nRows, size_t nCols);         // 1
        Matrix(Matrix const &other);                // 2

        Matrix(IniList inilist);                    // 4

        size_t size() const;

        class Proxy
        {
            size_t d_row = 0;

            public:
                Proxy(size_t row)
                :
                    d_row(row)
                {}

                DataType &operator[](size_t idx)
                {
                    return d_data[d_row * d_nCols + idx];
                }
        };

        Proxy &operator[](size_t idx);
};

template <typename DataType> 
inline Matrix<DataType>::Matrix(size_t nRows, size_t nCols)
:
    d_nRows(nRows),
    d_nCols(nCols),
    d_data(new DataType[size()]())
{}

template <typename DataType> 
inline Matrix<DataType>::Matrix(Matrix<DataType> const &other)
:
    d_nRows(other.d_nRows),
    d_nCols(other.d_nCols),
    d_data(new DataType[size()])
{
    memcpy(d_data, other.d_data, size() *sizeof(DataType));
}

template <typename DataType> 
inline Matrix<DataType>::Matrix(IniList iniList)
:
    d_nRows(iniList.size()),
    d_nCols(iniList.begin()->size()),
    d_data(new DataType[size()])
{
    auto ptr = d_data;
    for (auto &list: iniList)
    {
        if (list.size() != d_nCols)
        {
            std::cerr << "Matrix(IniList): varying number of elements in rows\n";

            exit(1);        // BAD STYLE, but see the exercise's text
        }

        memcpy(ptr, &*list.begin() , list.size() * sizeof(DataType));
        ptr += list.size();
    }
}

template <typename DataType> 
inline size_t Matrix<DataType>::size() const
{
    return d_nRows * d_nCols;
}

template <typename DataType>
std::ostream &operator<<(std::ostream &out, Matrix<DataType> const &matrix) 
{
    return out << "Name: " ;
}

template <typename DataType>
inline typename Matrix<DataType>::Proxy &Matrix<DataType>::operator[](size_t idx)
{
    Proxy proxy{ idx };
    return proxy;
}

#endif




