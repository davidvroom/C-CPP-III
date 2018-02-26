template <typename DataType>
Matrix<DataType>::~Matrix()
{
	delete[] d_data;
}
