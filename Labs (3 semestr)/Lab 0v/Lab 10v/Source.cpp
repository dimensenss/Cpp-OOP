#include "Header.h"
SUM::SUM(const int& x, const int& y ){
	this->x = x;
	this->y = y;
	this->sum = 0;
};
void SUM::setX(const int& x) { this->x = x; };
void SUM::setY(const int& y) { this->y = y; }
void SUM::PrintAllValues() { cout << "x   = " << x << "\n" << "y   = " << y << "\n" << "sum = " << sum << "\n\n"; }
void SUM::CalculateSum() { sum = x + y; }

