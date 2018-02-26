template <typename DataType, typename DataType2>
Matrix<DataType> operator+(Matrix<DataType> &&lhs, Matrix<DataType2> const &rhs) 
{
    lhs.add(rhs);
    return std::move(lhs);
}