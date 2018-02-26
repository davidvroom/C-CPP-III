template <typename DataType>
Matrix<DataType>::Matrix(Matrix &&tmp)
{
    swap(tmp);
}