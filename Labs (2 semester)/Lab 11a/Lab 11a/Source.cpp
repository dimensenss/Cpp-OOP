#include "Header.h"
point::point(const int& x, const int& y) {
	this->x = x;
	this->y = y;
}
point::point(const point& other) {
	this->x = other.x;
	this->y = other.y;
}
void point::setX(const int& x) { this->x = x; }
void point::setY(const int& y) { this->y = y; }
void point::foo(int& sum, int& product) {
	sum = x + y;
	product = x * y;
}
void point::print() { cout << "x = " << x << "\ny = " << y << endl; }
