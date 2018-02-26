template <typename DataType> 
Matrix<DataType>::Matrix(Matrix<DataType> const &other)
:
    d_nRows(other.d_nRows),
    d_nCols(other.d_nCols),
    d_data(new DataType[size()])
{
    memcpy(d_data, other.d_data, size() * sizeof(DataType));
}
