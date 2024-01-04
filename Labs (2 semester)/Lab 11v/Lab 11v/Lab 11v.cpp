#include "Header.h"
	
int main()
{
	int r1, m1, r2, m2;
	complex FirstComplex;
	complex SecondComplex;
	do {
		system("cls");
		cout << "Enter the real and imaginary part of a number:\n";
		cin >> r1 >> m1;
		if (cin.fail()) {
			cout << "Eror, try one more time\n";
			cin.clear();
			cin.ignore(32767, '\n');
			system("pause");
			system("cls");
			continue;
		}
		if (r1 > 0 && m1 > 0) {
			
			FirstComplex.SetR(r1);
			FirstComplex.SetM(m1);
		}
		else {
			cout << "Eror, try one more time\n";
			continue;
		}
		cout << "Enter the real and imaginary part of a number:\n";
		cin >> r2 >> m2;
		if (cin.fail()) {
			cout << "Eror, try one more time\n";
			cin.clear();
			cin.ignore(32767, '\n');
			system("pause");
			system("cls");
			continue;
		}
		if (r2 > 0 && m2 > 0) {

			SecondComplex.SetR(r2);
			SecondComplex.SetM(m2);
		}
		else {
			cout << "Eror, try one more time\n";
			continue;
		}
		

		(FirstComplex.Sum(SecondComplex)).print();
		FirstComplex.print();
		cout << "Press any key to continue . . .\n";
		puts("Press 'esc' to exit . . .");
	} while (_getch() != 27);
}