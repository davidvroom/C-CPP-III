template <typename DataType>
template <typename DataType2>
Matrix<DataType> &Matrix<DataType>::operator=(Matrix<DataType2> &&tmp)
{
    swap(tmp);
    return *this;
}