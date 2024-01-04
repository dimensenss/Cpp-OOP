#include <iostream>
#include <time.h>
#include <iomanip>
#include <cstdlib>
using namespace std;

	char foo(int first, int second) 
{
	//char sign;
	if (first > second)
	{
		return '>';
	}
	if (first < second)
	{
		return '<';
	}
	if(first == second)
	{
		return '=';
	}
	//return sign;
}

int main() 
{
	while (true)
	{
		setlocale(0, "rus");
		int first;
		int second;

		cout << "Введите первое число > ";
		cin >> first;
		cout << "Введите второе число > ";
		cin >> second;

		cout << endl;

		cout << first << setw(4) << foo(first, second) << setw(4) << second;

		cout << endl<<endl;
	}
}

