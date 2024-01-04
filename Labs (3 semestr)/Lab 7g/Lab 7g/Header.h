#pragma once
#include <iostream>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

class Base {
	string name;
	int age;
	friend fstream& operator <<(fstream& st, Base& ob);
	friend fstream& operator >>(fstream& st, Base& ob);
public:
	Base(const string& name = "None", const int& age = 0);
	Base(const Base& other);
	vector<Base*> input();
	void print(vector<Base*> base);
	void print();
	void writeToFile(Base& ob);
	Base readFromFile(int m);
	vector<Base*> readFromFileAll();
};
