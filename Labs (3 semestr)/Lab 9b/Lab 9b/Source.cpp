#include "Header.h"
Name::Name(const string& name, const string& last_name) {
	this->name = name;
	this->last_name = last_name;
}
Number::Number(const int& number) {
	this -> number = number;
}

ostream& operator<<(ostream& stream, const Name& ob1)
{
	cout << ob1.name << " " << ob1.last_name << " ";
	return stream;
}
ostream& operator<<(ostream& stream, const Number& ob1)
{
	cout << ob1.number << "\n";
	return stream;
}

