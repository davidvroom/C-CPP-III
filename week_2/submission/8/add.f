template <typename DataType>
template <typename DataType2>
void Matrix<DataType>::add(Matrix<DataType2> const &rhs)
{
    if (d_nRows != rhs.nRows() || d_nCols != rhs.nCols())
    {
        std::cerr << "Cannot add matrices of unequal dimensions\n";
        exit(1);
    }

	for (size_t row = 0; row != d_nRows; ++row)  
		for (size_t col = 0; col != d_nCols; ++col)  
          	(*this)[row][col] += rhs[row][col];
}
