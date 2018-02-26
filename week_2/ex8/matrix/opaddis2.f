template <typename DataType>
template <typename DataType2>
Matrix<DataType> &&Matrix<DataType>::operator+=(Matrix<DataType2> const &rhs) && 
{
    add(rhs); 
    return std::move(*this);  
}