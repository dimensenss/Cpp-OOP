#include "Header.h"
#include <conio.h>
int main()
{
	int sum, product,a,b;
	point FirstValue;
	FirstValue.print();
	FirstValue.foo(sum, product);
	cout << "sum = " << sum << "\nproduct = " << product << endl;
	cout << "\n";
	system("pause");
	do{
		system("cls");
		cout << "Enter x,y: ";
		cin >> a >> b;
		if (cin.fail()) {

			cout << "Eror, try one more time\n";
			cin.clear();
			cin.ignore(32767, '\n');
			system("pause");
			system("cls");
			continue;
		}
	FirstValue.setX(a);
	FirstValue.setY(b);
	FirstValue.print();
	FirstValue.foo(sum, product);
	cout << "sum = " << sum << "\nproduct = " << product << endl;
	cout << "\n";
	cout << "Enter x,y: ";
	cin >> a >> b;
	if (cin.fail()) {

		cout << "Eror, try one more time\n";
		cin.clear();
		cin.ignore(32767, '\n');
		system("pause");
		system("cls");
		continue;
	}
	point SecondValue(a,b);
	SecondValue.print();
	SecondValue.foo(sum, product);
	cout << "sum = " << sum << "\nproduct = " << product << endl;
	cout << "\n";
	point ThirdValue(FirstValue);
	ThirdValue.print();
	ThirdValue.foo(sum, product);
	cout << "sum = " << sum << "\nproduct = " << product << endl;
	cout << "Press any key to continue . . .\n";
	puts("Press 'esc' to exit . . .");

	} while (_getch() != 27);
}
