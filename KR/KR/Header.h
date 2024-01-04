#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <cmath>
#include <msclr\marshal.h>
#include <msclr/marshal_cppstd.h>

class Car {
	std::string name;
	std::string model;
public:

	virtual void random_car();
	Car();
	virtual void print(System::Windows::Forms::TextBox^ textBox);
	virtual std::string get_name() { return name; }
};

class Car_H : virtual public Car {
	float volume;
	int hp;
	int year;
	
public:
	virtual void print(System::Windows::Forms::TextBox^ textBox);
	virtual void random_car();
	int get_year() { return year; }
	Car_H();
};
class Car_Doc : public Car_H {
	int count_owner;
	bool dtp;
	
public:
	virtual void print(System::Windows::Forms::TextBox^ textBox);
	virtual void random_car();
	Car_Doc();
};
class AutoShow {
	std::vector<Car_Doc*> arr;
	
public:
	AutoShow();
	AutoShow(std::vector<Car_Doc*>& arr);
	AutoShow operator ()(std::vector<Car_Doc*>& arr1);
	virtual void print(System::Windows::Forms::TextBox^ textBox);
	void sort_year();
	void delete_ob(System::Decimal ob);
	void search(System::String^ str, System::Windows::Forms::TextBox^ textBox);
	int get_size() { return arr.size(); }
};

