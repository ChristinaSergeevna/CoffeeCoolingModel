#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

double F(double x, double y)
{
	return y * x;
}

int Euler(vector<double> &X, vector<double> &Y)
{
	double a = 0, b = 1, n = 0.1;
	double h = (b - a) / n;

	X[0] = a; Y[0] = 2;
	for (int i = 1; i < n; i++)
	{
		X[i] = a + i * h;
		Y[i] = Y[i - 1] + h * F(X[i - 1], Y[i - 1]);
	}
	return 0;
}

int MEuler(vector<double> &X, vector<double> &Y)
{
	double a = 0, b = 1, n = 0.1;
	double h = (b - a) / n;
	vector<double> Y1(n);

	X[0] = a; Y[0] = 2;
	for (int i = 1; i < n; i++)
	{
		X[i] = a + i * h;
		Y1[i] = Y[i - 1] + h * F(X[i - 1], Y[i - 1]);
		Y[i] = Y[i - 1] + h * (F(X[i - 1], Y[i - 1]) + F(X[i], Y1[i])) / 2.0;
	}
	return 0;
}

int EulerCauchy(vector<double> &X, vector<double> &Y)
{
	double a = 0, b = 1, n = 0.1;
	double h = (b - a) / n;
	vector<double> Y1(n);

	X[0] = a; Y[0] = 2;
	for (int i = 1; i < n; i++)
	{
		X[i] = a + i * h;
		Y1[i] = h * F(X[i - 1] + h / 2, Y[i - 1] + h * F(X[i], Y[i]) / 2);
		Y[i] = Y[i - 1] + Y1[i];
	}
	return 0;
}

int RungeKutta4(vector<double> &X, vector<double> &Y)
{
	double a = 0, b = 1, n = 0.1;
	double h = (b - a) / n;
	vector<double> Y1(n);
	vector<double> Y2(n);
	vector<double> Y3(n);
	vector<double> Y4(n);

	X[0] = a; Y[0] = 2;
	for (int i = 1; i < n; i++)
	{
		X[i] = a + i * h;
		Y1[i] = h * F(X[i - 1], Y[i - 1]);
		Y2[i] = h * F(X[i - 1] + h / 2.0, Y[i - 1] + Y1[i] / 2.0);
		Y3[i] = h * F(X[i - 1] + h / 2, Y[i - 1] + Y2[i] / 2);
		Y4[i] = h * F(X[i - 1] + h, Y[i - 1] + Y3[i]);
		Y[i] = Y[i - 1] + (Y1[i] + 2 * Y2[i] + 2 * Y3[i] + Y4[i]) / 6;
	}
	return 0;
}