template <typename DataType> 
Matrix<DataType>::Matrix(IniList iniList)
try
:
    d_nRows(iniList.size()),
    d_nCols(iniList.begin()->size()),
    d_data(new DataType[size()])
{
    auto ptr = d_data;
    for (auto &list: iniList)
    {
        if (list.size() != d_nCols)
            throw std::out_of_range("Matrix(IniList): varying number of elements in rows\n");

        memcpy(ptr, &*list.begin() , list.size() * sizeof(DataType));
        ptr += list.size();
    }
}
catch (std::out_of_range& exc) 
{
    std::cerr << exc.what();
    delete[] d_data;
}
catch(...)
{}
