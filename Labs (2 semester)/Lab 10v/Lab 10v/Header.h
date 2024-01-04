#pragma once
#include <iostream>
using namespace std;

class SUM {
	int x, y, sum;
public:
	SUM(const int& x = 0, const int& y = 0);
	void setX(const int& x);
	void setY(const int& y);
	void PrintAllValues();
	void CalculateSum();
};