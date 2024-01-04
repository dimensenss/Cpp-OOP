#include "Header.h"
Persona::Persona(const string& name , const int& age ){
	this->name = name;
	this->age = age;
}

Prepod::Prepod(const string& name , const int& age , const string& lesson , const int& stupin ):Persona(name, age) {
	this->lesson = lesson;
	this->stupin = stupin;
}

void Prepod::print()
{
	string s;
	if (this->stupin == 0)
		s = "None";
	else if (this->stupin == 1)
		s = "ktn";
	else if (this->stupin == 2)
		s = "dtn";
	else
		s = "None";
	if (typeid(*this) == typeid(Prepod))
		cout << "Prepod\n";
	else
		cout << "Zav_Kaf\n";

	cout <<"Name: " << this->get_name() << "\n" << "Age: " << this->get_age() << "\n" << "Lesson: " << this->lesson << "\n" << "Stupin: " << s << "\n";
}
Student::Student(const string& name, const int& age,  int* marks) :Persona(name, age) {
	this->marks = marks;
}
void Student::print() {
	cout << "Student\n";
	cout << "Name: " << this->get_name() << "\n" << "Age: " << this->get_age() << "\n" << "Marks: ";
	for (int i = 0; i < 5; i++) { cout << "[" << this->marks[i]<< "] "; }
	cout << "\n";
}
int Student::ask() {
	int k =0;
	for (int i = 0; i < 5; i++) {
		if (this->marks[i] == 2)
			++k;
	}
	return k;
}
Zav_Kaf::Zav_Kaf(const string& name, const int& age,const string& lesson, const int& stupin, const string& posada): Prepod(name, age, lesson, stupin){
	this->posada = posada;
}
int Zav_Kaf::ask() {
	return get_age();
}
void Zav_Kaf::print() {
	Prepod::print();
	cout <<"Posada: " << this->posada << "\n";
}

void Vuz::age_under_50(vector<Persona*> Shtat) {
	for (int i = 0; i < Shtat.size(); i++) {
		if (Shtat[i]->get_age() < 50 && (Shtat[i]->who() == 1 || Shtat[i]->who()==2))//&& (typeid(*Shtat[i]) == typeid(Prepod)))
			Shtat[i]->print();
	}
}
void Vuz::borg(vector<Persona*> Shtat) {
	for (int i = 0; i < Shtat.size(); i++) {
		if ((typeid(*Shtat[i]) == typeid(Student)) && Shtat[i]->ask() >= 1)
			Shtat[i]->print();
	}
}