template <typename DataType, typename DataType2>
Matrix<DataType> operator+(Matrix<DataType> const &lhs, Matrix<DataType2> const &rhs) 
{
    Matrix<DataType> tmp(lhs);
    tmp.add(rhs);
    return tmp;
}