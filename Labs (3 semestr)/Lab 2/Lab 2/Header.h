#pragma once
#include <iostream>
#include <iomanip>
#include <conio.h>          
using namespace std;

class Table {
	string name;
	char type;
	string humidity;
	float count;
	friend ostream& operator<<(ostream& stream, Table& o1);
	friend istream& operator>>(istream& stream, Table& o1);
	friend Table operator + (const Table& ob1, const Table& ob2);
	friend bool operator == (const Table& ob1, const Table& ob2);
public:
	Table(const string& name = "None", const char& type = 'T', const string& humidity = "0", const float& count = 0);
	void Set(const string& name,const char& type, const string& humidity, const float& count);
	void Get(string& name, char& type, string& humidity, float& count);
    //Table operator + (const Table& ob);
	Table operator = (const Table& ob);
	//bool operator == (const Table& ob);
	int* operator[](const Table& ob);
	Table operator () (const string& name, const char& type, const string& humidity, const float& count);
};
