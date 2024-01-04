#include "Header.h"
Table::Table(const string& name, const char& type, const string& humidity, const float& count)
{
	this->name = name;
	this->type = type;
	this->humidity = humidity;
	this->count = count;
}
void Table::Set(const string& name, const char& type, const string& humidity, const float& count) {
	this->name = name;
	this->type = type;
	this->humidity = humidity;
	this->count = count;
}
void Table::Get(string& name, char& type, string& humidity, float& count) {
	name = this->name;
	type = this->type;
	humidity = this->humidity;
	count = this->count;
}

ostream& operator<<(ostream& stream, Table& o1) {
	//o1.Show();
	cout << setw(10) <<"Name " << setw(2) <<"\tType " << setw(2) <<"\tHumidity " << setw(10) << "Count " << "\n";
	stream << "|" << setw(10) << o1.name << "  |  ";
	stream << setw(5) << o1.type << "|";
	stream << setw(11) << o1.humidity << "  |";
	stream << setw(4) << o1.count << "  |" << endl;
	cout << "-------------------------------------------\n";
	return stream;
}

istream& operator>>(istream& stream, Table& o1) {
	cout << "Name = "<< "\tType = " << "\tHumidity = "  << "\tCount = " << "\n";
	stream >> o1.name;
	stream >> o1.type;
	stream >> o1.humidity;
	stream >> o1.count;
	return stream;
}
//Table Table::operator + (const Table& ob) {
//	Table temp;
//	temp.name = this->name +'+'+ ob.name;
//	temp.type = int(this->type) + 1;
//	temp.humidity = this->humidity + '+' + ob.humidity;
//	temp.count = this->count + ob.count;
//	return temp;
//}
// bool Table::operator ==(const Table& ob){
//	return (name == ob.name && type == ob.type && humidity == ob.humidity && count == ob.count);
//}
Table Table::operator = (const Table& ob) {
	name = ob.name;
	type = ob.type;
	humidity = ob.humidity;
	count = ob.count;
	return *this;
}

bool operator == (const Table& ob1, const Table& ob2) {
	return(ob1.name == ob2.name && ob1.type == ob2.type && ob1.humidity == ob2.humidity && ob1.count == ob2.count);
}
Table operator + (const Table& ob1, const Table& ob2) {
	Table temp;
	temp.name = ob1.name +'+'+ ob2.name;
	temp.type = int(ob1.type) + 1;
	temp.humidity = ob1.humidity + '+' + ob2.humidity;
	temp.count = ob1.count + ob2.count;
	return temp;	
}
int* Table::operator[](const Table& ob) {
	int* mas = new int;
	if (!ob.name.empty() && !ob.humidity.empty()) {
		mas = new int[2];
		mas[0] = ob.name.size();
		mas[1] = ob.humidity.size();
		return mas;
	}
	else {
		cout << "Eror ob is empty";
		return mas;
	}
	
}
Table Table::operator () (const string& name, const char& type, const string& humidity, const float& count) {
	this->name = name;
	this->type = type;
	this->humidity = humidity;
	this->count = count;
	return *this;
}