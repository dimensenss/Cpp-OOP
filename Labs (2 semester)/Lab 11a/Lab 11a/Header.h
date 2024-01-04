#pragma once
#include <iostream>
using namespace std;

class point {
	int x, y;
public:
	point(const int& x = 0, const int& y = 0);
	point(const point& other); 
	void setX(const int& x);
	void setY(const int& y);
	void foo(int& sum, int& product);
	void print();
};