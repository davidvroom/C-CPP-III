#include <iostream>
#include "exception/exception.h"

using namespace std;

int main(int argc, char **argv)
try
{
	string str = "I'm a string";
    throw Exception{} << "insert anything that's ostream-insertable: "
                      << str << argc << '!';
}
catch (exception const &ex)   
{
    cout << ex.what() << '\n';
}
