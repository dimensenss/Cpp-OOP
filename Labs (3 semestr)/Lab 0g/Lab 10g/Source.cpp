#include "Header.h"
Timer::Timer(const int& sec)
{
	this->sec = sec;

	cout << "constructor " << this << endl;

}
Timer::Timer(const int& sec, const int& min)
{
	this->sec = sec + min * 60;
	cout << "constructor " << this << endl;
}

Timer::Timer(const Timer& other) {
	this->sec = other.sec;
	cout << "constructor " << this << endl;
}
void Timer::print() {
	cout << "sec = " << sec << endl;
}
