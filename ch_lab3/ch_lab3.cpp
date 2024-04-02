#include <iostream>
#include <omp.h>

const int size = 3;
double matrix[size][size + 1] = { {1,1,1,6},{1,-1,2,5},{2,-1,-1,-3} };

int main()
{
	for (int i = 0; i < size - 1; i++)
	{
		#pragma omp parallel for
		for (int j = i + 1; j < size; j++)
		{		
			double n = matrix[j][i] / matrix[i][i];
			for (int k = i; k < size + 1; k++)
			{
				matrix[j][k] = matrix[j][k] - matrix[i][k] * n;				
			}
		}
	}
	/*for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << '\n';
	}
	std::cout << '\n';*/
	double n = 0;
	for (int i = size-1; i >= 0; i--)
	{	

		n = 0;
		for (int k = i + 1; k < size; k++)
		{
			n = n + matrix[i][k];			
		}		

		matrix[i][size] = matrix[i][size] - n;

		int x = matrix[i][size] / matrix[i][i];
		std::cout << "x="<< x << '\n';

		for (int j = i - 1; j >= 0; j--)
		{
			matrix[j][i] = matrix[j][i] * x;
		}
	}
	std::cout << "qwerty";
}


