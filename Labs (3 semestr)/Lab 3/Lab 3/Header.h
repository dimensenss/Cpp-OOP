#pragma once
#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;
class B {
protected: int b;
public:
	B(int x) :b(x) {}
	virtual void show() { cout << "B = " << b << endl; }
	virtual ~B() {}
};
class D1 : virtual public B {
protected: int d1;
public:
	D1(int x, int y) :B(x), d1(y) {}
	virtual void show() { cout << "D1 = " << d1 << " B = " << b << endl; }
	virtual ~D1() {}
};
class D2 : virtual protected B {
protected: int d2;
public:
	D2(int x, int y) :B(x), d2(y) {}
	virtual void show() { cout << "B = " << b << " D2 = " << d2 << endl; }
	virtual ~D2() {}
};
class D3 : public D2 {
protected: int d3;
public:
	D3(int x, int y, int i) :B(x),  D2(x, y), d3(i) {}
	virtual void show()override {
		cout << "B = " << b << " D2 = " << d2;
		cout << " D3 = " << d3 << endl;
	}
	virtual ~D3() {}
};
class D4 :protected D1, private D3 {
protected: int d4;
public:
	D4(int x, int y, int i, int j, int n) :B(x), D1(99, y), D3(x, i, j), d4(n) {}
	virtual void show()override {
		cout << "B = " << b << " D1 = " << d1;
		cout << " D2 = " << d2 << " D3 = " << d3 <<" D4 = " << d4 << endl;
	}
	virtual ~D4() {}
};
