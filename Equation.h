#pragma once

#include <iostream>
#include <cmath>
#include <vector>
#include "MyForm.h"

using namespace std;

class Equation {
public:
	double TempCoffe, TempAir;
	double Rate;
	double Time, Steps;
	int GetEuler, GetEulerM, GetEulerC, GetRungK;

	Equation(double tc, double ta, double r, double t, double s) : TempCoffe(tc), TempAir(ta), Rate(r), Time(t), Steps(s) {}
	void GetVal(double VTempCoffe, double VTempAir, double Vrate, double VTime, double VSteps);
	void CheckMethods(int Euler, int EulerM, int EulerC, int RungK);
};

void Equation::CheckMethods(int Euler, int EulerM, int EulerC, int RungK) {
	if (Euler) {

	}
	if (EulerM) {

	}
	if (EulerC) {

	}
	if (RungK) {

	}
}

void Equation::GetVal(double VTempCoffe, double VTempAir, double VRate, double VTime, double VSteps) {

}