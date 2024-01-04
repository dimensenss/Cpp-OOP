#include "Header.h"
#include <conio.h>
int main()
{

	cout << "default constructor with setters:\n\n";
	SUM FirstValue;
	FirstValue.CalculateSum();
	FirstValue.PrintAllValues();
	int a, b;
	do{
	//system("cls");
	cout << "Enter 2 numbers: ";
	cin >> a>> b;
	if (cin.fail()) {

		cout << "Eror, try one more time\n";
		cin.clear();
		cin.ignore(32767, '\n');
		system("pause");
		system("cls");
		continue;
	}
	//FirstValue.CalculateSum();
	FirstValue.setX(a);
	FirstValue.setY(b);
	FirstValue.CalculateSum();
	FirstValue.PrintAllValues();

	cout << "constructor with parameters:\n\n";
	cout << "Enter 2 numbers: ";
	cin >> a >> b;
	if (cin.fail()) {

		cout << "Eror, try one more time\n";
		cin.clear();
		cin.ignore(32767, '\n');
		system("pause");
		system("cls");
		continue;
	}
	SUM SecondValue(a, b);
	SUM* pointer = &SecondValue;

	pointer->CalculateSum();
	pointer->PrintAllValues();
	cout << "Press any key to continue . . .\n";
	puts("Press 'esc' to exit . . .");
	SUM &ref = SecondValue;
	ref.CalculateSum();
	ref.PrintAllValues();
	
	} while (_getch() != 27);

}