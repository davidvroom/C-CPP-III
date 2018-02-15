#include <iostream>

using namespace std;

template <typename Type>
inline Type const &max(Type const &left, Type const &right)
{
    return left > right ? left : right;
}

/*double max(double const &left, double const &right)
{
    return left > right ? left : right;
}*/

int main()
{
    cout << ::max<double>("3.5", 4) << endl;
}