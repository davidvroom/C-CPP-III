template <typename DataType> 
Matrix<DataType>::Matrix(size_t nRows, size_t nCols)
:
    d_nRows(nRows),
    d_nCols(nCols),
    d_data(new DataType[size()]())
{}