#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
class replaceValues
{
private:
	void swap(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}
public:
	void Swap(int& a, int& b, int& c)
	{
		int min, max, temp;
		min = a; max = a;
		if (b < min)
			min = b;
		
		if (c < min) 
			min = c;
		
		if (b > max) 
			max = b;
		
		if (c > max)
			max = c;
		
		if (((a == max) && (b == min)) || 
			((a == min) && (b == max))) 
			swap(a, b);
		
		if (((b == max) && (c == min)) || 
			((b == min) && (c == max))) 
			swap(b, c);
		
		if (((a == max) && (c == min)) || 
			((a == min) && (c == max))) 
			swap(a, c);
		
	}
	void Swap(int* a, int* b, int* c)
	{
		int min, max, temp;
		min = *a; max = *a;
		if (*b < min)
			min = *b;
		
		if (*c < min)
			min = *c;
		
		if (*b > max)
			max = *b;
		
		if (*c > max)
			max = *c;
		
		if (((*a == max) && (*b == min)) || 
			((*a == min) && (*b == max))) 
			swap(*a, *b);
		
		if (((*b == max) && (*c == min)) || 
			((*b == min) && (*c == max))) 
			swap(*b, *c);
		
		if (((*a == max) && (*c == min)) || 
			((*a == min) && (*c == max))) 
			swap(*a, *c);
	}
};
int main()
{
	replaceValues value;
	int a, b, c;
	do
	{
		system("cls");
		cout << "Enter a, b, c\n";
		cin >> a >> b >> c;
		if (cin.fail()) {
			cout << "Eror, try one more time\n";
			cin.clear();
			cin.ignore(32767, '\n');
			system("pause");
			system("cls");
			continue;
		}
			system("cls");
			cout << "Before swap:\na = " << a << " b = " << b << " c = " << c << endl;
			value.Swap(&a, &b, &c);
			cout << "After swap by link:\na = " << a << " b = " << b << " c = " << c << endl;
			cout << "Before swap:\na = " << a << " b = " << b << " c = " << c << endl;
			value.Swap(a, b, c);
			cout << "After swap by pointers:\na = " << a << " b = " << b << " c = " << c << endl;
			cout << "\n";
		cout << "Press any key to continue . . .\n";
		puts("Press 'esc' to exit . . .");
	} while (_getch() != 27);
}

