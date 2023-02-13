#include <iostream> 
#include <math.h> 
#include <windows.h>

using namespace std;

void Out(double* matrix, int i)				//Test
{
	for (int j = 0; j < i; j++)
	{
		cout << matrix[j] << " ";
	}
	cout << "\n\n";
}

double summ(double* matrix) 
{
	double S = 0;
	for (int j = 0; j < 3; j++)
	{
		if (j != 0)
		S += 1 / (matrix[0] - matrix[j]);
	}
	return S;
}
double Polinom(double* matrix, int length, int i)
{
	double  Denom = 1;

	for (int j = 0; j < length; j++)
	{
		if (j != i)
		{
			Denom *= (matrix[i] - matrix[j]);
		}
		
	}
	return Denom;
}
double multi(double* matrix, int length)
{
	double m = 1;

	for (int j = 1; j < length; j++)
	{
		m = m * (matrix[0] - matrix[j]);
	}
	return m;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	double h = 0.1, y0 = 0, first = 0, derivative_1 = 0, derivative_2 = 0;
	int len = 4, j = 0;
	double* X = new double[11];
	double* Y = new double[11];
	X[0] = 1;


	for ( j = 1; j < 11; j++)							//Заполнеиние Х
	{
		X[j] = X[j - 1] + 0.1;
	}
	cout << "X" << "\n";
	Out(X, 11);

	for (j = 0; j < 11; j++)							//Заполнение Y
	{
		Y[j] = X[j] * log(X[j]);
	}
	cout << "Y" << "\n";
	Out(Y, 11);
	

		for ( j = 0; j < len; j++)
		{
			if (j == 0)
			{
				for (int k = 1; k < len; k++)
				{
					y0 += (1 / (X[0] - X[k]));
				}
				y0 *= Y[0];
			}
			else
			{
				derivative_1  += Y[j] *(1 / (X[0] - X[j])) * (1 / Polinom(X, len, j));
			}
		}
		derivative_1 = derivative_1 * multi(X, len) + y0;
		y0 = 0;
	
	cout << "Производная первого порядка:" << "\n";
	cout << derivative_1 << "\n\n";

		for (j = 0; j < len; j++)
		{
			if (j == 0)
			{
				y0 += (1 / (X[0] - X[2])) + (1 / (X[0] - X[3]));
				y0 *= 1 / (X[0] - X[1]); 
				y0 += 1 / ((X[0] - X[2]) * (X[0] - X[3]));
				y0 *= Y[0];
			}
			else
			{
				derivative_2 += Y[j] * (1 / (X[0] - X[j])) * (1 / Polinom(X, len, j)) * summ(X);
			}
		}
		derivative_2 = 2* (derivative_2 * multi(X, len) + y0);

	cout << "Производная второго порядка:" << "\n";
	cout << derivative_2 << "\n\n";
}