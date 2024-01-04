#pragma once
#include <iostream>
using namespace std;
class Timer {
	int sec;
public:
	Timer(const int& sec);
	Timer(const int& sec, const int& min);
	Timer(const Timer& other);
	void print();
	~Timer() {cout << "destructor " << this << endl;}

};