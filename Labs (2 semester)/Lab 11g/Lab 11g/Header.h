#pragma once
#include <iostream>
#include "Windows.h"
#include <iomanip>
#include <conio.h>
#include <vector>
using namespace std;
class dog {
	string name;
	int weight;
	int age;
	static int DogsCount;
public:
	dog(const int& weight = 0, const int& age = 0, const string& name = "No name dog" );
	dog(const dog& other);
	void SetDogsMerit(const string& name, const int& weight, const int& age);
	void GetDogsMerit();
	static int GetDogsCount();
	
};

class master {
	string name;
	const int id = 6597;
	static int MasterCount;
	dog* dogs;
public:
	
	master(dog* dogs = new dog(), const string& name = "No name person");
	master(const master& other);
	void SetMastersMerit(const string& name, dog* dogs);
	void GetMastersMerit();
	static int GetMastersCount();
	void GetMastersDogsMerit(int count);
	dog GetDogs(int count, static int& j);
};