template <typename DataType>
template <typename DataType2>
Matrix<DataType> &Matrix<DataType>::operator=(Matrix<DataType2> const &rhs)
{
    Matrix<DataType> tmp(rhs);
    swap(tmp);
    return *this;
}