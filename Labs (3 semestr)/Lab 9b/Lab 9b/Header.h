#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <Windows.h>

using namespace std;
class Name {
	string name;
	string last_name;
	friend ostream& operator<<(ostream& stream, const Name& ob1);
public:
	friend bool operator < (const Name& d1, const Name& d2) {
		return d1.name < d2.name;
	}
	bool operator()(const Name& d1, const Name& d2) const {
		return d1.last_name < d2.last_name;
	}
	Name(const string& name = "None", const string& last_name = "None");
	
	string get_last_name() { return last_name; }
	string get_name() { return name; }
};
class Number {
	int number;	
	friend ostream& operator<<(ostream& stream, const Number& ob1);

public:
	Number(const int& number = 0);
	int get_num() { return number; }
};

