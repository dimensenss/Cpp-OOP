#include "Header.h"
#include <conio.h>

int main()
{ 
	int a, b;
	do{
	cout << "\nEnter sec:";
	cin >> a;
	if (cin.fail()) {

		cout << "Eror, try one more time\n";
		cin.clear();
		cin.ignore(32767, '\n');
		system("pause");
		system("cls");
		continue;
	}
	Timer FirstValue(a);
	cout << "Enter sec and min:";
	cin >> a>>b;
	if (cin.fail()) {

		cout << "Eror, try one more time\n";
		cin.clear();
		cin.ignore(32767, '\n');
		system("pause");
		system("cls");
		continue;
	}
	Timer SecondValue(a, b);
	Timer ThirdValue(FirstValue);
	FirstValue.print();
	SecondValue.print();
	ThirdValue.print();

	cout << "Press any key to continue . . .\n";
	puts("Press 'esc' to exit . . .");

	} while (_getch() != 27);
}