template <typename Type1, typename Type2>

Type1 as(Type2 const &value)
{
	return static_cast<Type1>(value);
}
