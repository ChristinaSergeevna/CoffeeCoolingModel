#pragma once

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class Equation {
public:
	double TCoffee, TRoom;
	double r;
	double time, n;
	int selectEuler, selectEulerM, selectEC, selectRK4;
	vector< vector<double> > table;

	Equation() {}
	Equation(double tc, double ta, double r, double t, double s) : TCoffee(tc), TRoom(ta), r(r), time(t), n(s) {}

	double F(double r, double Tc, double Tr)
	{
		return -r * (Tc - Tr);
	}

	double pukF()
	{

	}

	vector<double> Euler()
	{
		vector<double> X(n), Y(n);
		double h = time / n;
		X[0] = 0; Y[0] = TCoffee;

		for (int i = 1; i < n; i++)
		{
			X[i] = i * h;
			Y[i] = Y[i - 1] + h * F(r, Y[i - 1], TRoom);
		}
		return Y;
	}

	vector<double> MEuler()
	{
		vector<double> X(n), Y(n);
		double h = time / n;
		X[0] = 0; Y[0] = TCoffee;

		vector<double> Y1(n);

		for (int i = 1; i < n; i++)
		{
			X[i] = i * h;
			Y1[i] = Y[i - 1] + h * F(r, Y[i - 1], TRoom);
			Y[i] = Y[i - 1] + h * (F(r, Y[i - 1], TRoom) + F(r, Y1[i], TRoom)) / 2.0;
		}
		return Y;
	}

	vector<double> EulerCauchy()
	{
		vector<double> X(n), Y(n);
		double h = time / n;
		X[0] = 0; Y[0] = TCoffee;

		vector<double> Y1(n);

		for (int i = 1; i < n; i++)
		{
			X[i] = i * h;
			Y1[i] = h * F(r, Y[i - 1] + h / 2, TRoom + h * F(r, Y[i], TRoom) / 2);
			Y[i] = Y[i - 1] + Y1[i];
		}
		return Y;
	}

	vector<double> RungeKutta4()
	{
		vector<double> X(n), Y(n);
		double h = time / n;
		X[0] = 0; Y[0] = TCoffee;

		vector<double> Y1(n);
		vector<double> Y2(n);
		vector<double> Y3(n);
		vector<double> Y4(n);

		for (int i = 1; i < n; i++)
		{
			X[i] = i * h;
			Y1[i] = h * F(r, Y[i - 1], TRoom);
			Y2[i] = h * F(r, Y[i - 1] + h / 2.0, TRoom + Y1[i] / 2.0);
			Y3[i] = h * F(r, Y[i - 1] + h / 2, TRoom + Y2[i] / 2);
			Y4[i] = h * F(r, Y[i - 1] + h, TRoom + Y3[i]);
			Y[i] = Y[i - 1] + (Y1[i] + 2 * Y2[i] + 2 * Y3[i] + Y4[i]) / 6;
		}
		return Y;
	}
};
