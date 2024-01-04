#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
class complex {
	double r, m;
	void AddR(const double& r);
	void AddM(const double& m);
public:
	complex(const double& r = 0, const double& m = 0);
	void SetR(const double& r);
	void SetM(const double& m);
	complex Sum(const complex& other);
	void print();
};