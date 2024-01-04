#pragma once

#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

class Persona {
	string name;
	int age;
public:
	Persona(const string& name = "None", const int& age = 0);
	virtual void print() = 0;
	virtual int who() = 0;
	virtual int ask() = 0;
	string get_name() { return name; }
	int get_age() { return age; }
 };

class Prepod: public Persona {
	string lesson;
	int stupin;
public:
	Prepod(const string& name = "None", const int& age = 0, const string& lesson = "None", const int& stupin = 0);
	virtual int who() override { return 1; }
	virtual int ask() override { return stupin; }
	virtual void print() override;
};
class Student :  public Persona {
	int* marks;
public:
	Student(const string& name = "None", const int& age = 0,  int* marks = nullptr);
	virtual int who() override { return 3; }
	virtual int ask() override;
	virtual void print() override;
};
class Zav_Kaf :  public Prepod {
	string posada;
public:
	Zav_Kaf(const string& name = "None", const int& age = 0, const string& lesson = "None", const int& stupin = 0, const string& posada = "None");
	virtual int who() override { return 2; }
	virtual int ask() override;
	virtual void print() override;
};
class Vuz {
public:
	void age_under_50(vector<Persona*> Shtat);
	void borg(vector<Persona*> Shtat);
};