#include "matrix/matrix.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//Matrix<double> Hai{2,2};
	Matrix<int> matrix
	{
		{1, 2},
		{3, 4}
	};

	Matrix<double> Hai
	{
		{1, 1},
		{1, 1}
	};
	Hai += matrix;

	Matrix<double> Dag(2,2);

	Dag = Hai + matrix + Hai;

	//Matrix<double> matrix2{move(matrix)};

	//cin >> Hai;

	cout << Hai;
	cout << Dag;
	cout << matrix;
	cout << matrix[0][0];

	cout << (Hai != matrix);
}
