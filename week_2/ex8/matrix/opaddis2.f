template <typename DataType>
template <typename DataType2>
Matrix<DataType> &&Matrix<DataType>::operator+=(Matrix<DataType2> const &rhs) && 
{
    add(rhs); // directly add rhs to *this,
    return std::move(*this); // return *this as rvalue ref. 
}