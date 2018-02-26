template <typename DataType>
template <typename DataType2>
Matrix<DataType> &Matrix<DataType>::operator+=(Matrix<DataType2> const &other) & 
{
    Matrix<DataType> tmp(*this);
    tmp.add(other);
    swap(tmp);
    return *this;
}