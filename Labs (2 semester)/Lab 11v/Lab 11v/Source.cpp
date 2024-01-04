#include "Header.h"
void complex::AddR(const double& r) {
	this->r += r;
}
void complex::AddM(const double& m) {
	this->m += m;
}
complex::complex(const double& r, const double& m ){
	this->r = r;
	this->m = m;
}
void complex::SetR(const double& r) {
	this->r = r;
}
void complex::SetM(const double& m) {
	this->m = m;
}
complex complex::Sum(const complex& other) {
	/*AddR(other.r);
	AddM(other.m);*/
	complex A;
	A.r = this->r + other.r;
	A.m = this->m + other.m;
	return A;
}
void complex::print() {
	cout << r << " + " << m << "i" << endl;
}