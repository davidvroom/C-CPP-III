template <typename DataType>
void Matrix<DataType>::swap(Matrix &other)
{
    char buffer[sizeof(Matrix)];
    memcpy(buffer, this,   sizeof(Matrix));
    memcpy(this,   &other, sizeof(Matrix));
    memcpy(&other, buffer, sizeof(Matrix));
}