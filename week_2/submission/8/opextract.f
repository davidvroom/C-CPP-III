template <typename DataType>
std::istream &operator>>(std::istream& in, Matrix<DataType> const &matrix)
{
    for (size_t idx = 0; idx != matrix.size(); ++idx)
        in >> matrix[idx];

    return in;
}