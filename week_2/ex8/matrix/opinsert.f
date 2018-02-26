template <typename DataType2>
std::ostream &operator<<(std::ostream &out, Matrix<DataType2> const &matrix) 
{
    for (size_t rowIdx = 0; rowIdx != matrix.d_nRows; ++rowIdx)
    {
        for (size_t colIdx = 0; colIdx != matrix.d_nRows; ++colIdx)
            out << matrix.el(rowIdx, colIdx) << ' ';
        out << '\n';
    }

    return out;
}