#include <iostream>
#include <conio.h>
#define N 3
using namespace std;
class table {
	string name;
	char type;
	string humidity;
	float count;
public:
	void Set(string name, char type, string humidity, float count);
	void Get(string& name, char& type, string& humidity, float& count);
	void Show();
};
void table::Set(string name, char type, string humidity, float count) {
	this->name = name;
	this->type = type;
	this->humidity = humidity;
	this->count = count;
}
void table::Get(string& name, char& type, string& humidity, float& count) {
	name = this->name + "111";
	type = this->type;
	humidity= this->humidity;
	count = this->count;
}
void table::Show() {
	cout << "--------------------------------------------------------------\n";
	cout << "Name = " << name << "\tType = " << type << "\tHumidity = " << humidity << "\tCount = " << count<<"\n";
	cout << "--------------------------------------------------------------\n";
}
int main() {
	string name;
	char type;
	string humidity;
	float count;

	table FirstObject[N];
	for (int i = 0; i < N; i++) {
		system("cls");
		cout << "Enter Thermal conductivity coefficients of materials\n";
		cin >> name;
		cin >> type;
		cin >> humidity;
		cin >> count;
		FirstObject[i].Set(name, type, humidity, count);
	}
	cout << "Set\n";
	for (int i = 0; i < N; i++)
		FirstObject[i].Show();

	cout << "\n\n\nGet\n";
	for (int i = 0; i < N; i++) {
		FirstObject[i].Get(name, type, humidity, count);
		FirstObject[i].Show();
	}
}
