#include "data.h"
#include <string>

using namespace std;

int main()
{
    Data data;

    string str{"12.4"};
    double d = stold(str);

    ///...                     // assume data is filled with at least 4
                            // strings. 

    //data.get<int>(3);       // returns d_data[3] converted to int or 0, if
                            // the conversion fails

    //data.get<long double>(1);   // returns d_data[1] converted to a long
                            // double or 0, if the conversion fails

    string str2;
    str2 = data.get<string>(2);    // returns d_data[2] as std::string const & 
}
