#include "Header.h"
Base::Base(const string& name, const int& age) {
	this->name = name;
	this->age = age;
}
Base::Base(const Base& other) {
	this->name = other.name;
	this->age = other.age;
}
vector<Base*> Base::input() {
	int n;
	vector<Base*> base;
	srand(time(NULL));
	try {
		cout << "How many objects create? ";
		cin >> n;
		if (n <= 0) {
			throw exception("Error, num <= 0");
		}
		
		for (int i = 0; i < n; i++) {			
			int m = rand() %100;
			string s = "name";
			s.append(to_string(i));
			base.push_back(new Base(s, m));
		}
		
	}
	catch (const exception& ex) {
		cout << ex.what() << "\n";

	}
	return base;
}
void Base::print(vector<Base*> base) {
	for (int i = 0; i < base.size(); i++) {
		cout<<base[i]->name<<" ";
		cout << base[i]->age<<"\n";
	}

}
void Base::print() {
	cout << name << " ";
	cout << age << "\n";
}
fstream& operator <<(fstream& st, Base& ob) {
	st << ob.name << " " << ob.age<<"\n";
	return st;
}
fstream& operator >>(fstream& st, Base& ob) {
	st >> ob.name >> ob.age;
	return st;
}
void Base::writeToFile( Base& ob) {
	fstream f;

	f.open("text.txt", ios::app);
	f << ob;
	f.close();
}
Base Base::readFromFile(int m) {
	fstream f;
	Base temp;
	f.open("text.txt", ios::in);
	try {
		
		if (m < 0) {
			throw exception("Error, num < 0");
		}
		for (int i = 0; i < m; i++)
			while (f && f.get() != '\n');

		f >> temp;
		if (temp.name == "None") {
			throw exception("Error ob doesnt exist in file");
			
		}
		f.close();
		return temp;
	}
	catch (const exception& ex) {
		cout << ex.what() << "\n";
		return temp;

	}
}
vector<Base*> Base::readFromFileAll() {
	fstream f;
	Base temp;
	vector <Base*>base;
	f.open("text.txt", ios::in);
	try {
		while (!f.eof()) {
			f >> temp;

			
			if (temp.name == "None") {
				throw exception("File is empty");

			}
			base.push_back(new Base(temp.name, temp.age));
		}
		f.close();
		return base;
	}

	catch (const exception& ex) {

		cout << ex.what() << "\n";
		return base;

		cout << ex.what() << "\n";

	}
}
