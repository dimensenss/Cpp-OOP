#include <iostream>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

void foo(int i, int arr[])
{
	static int j = 0;
	if (i == 0)
		cout << 0;
	else
	{
		if (i / 8 > 0)
		{
			foo(i / 8, arr);
		}
		arr[j] = i % 8;
		j++;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");

	int i = 0;
	int_fast64_t  m = 0;
	int stepen = 0;
	int p = 0;
	int arr[11];

	cout << "Введите число в десятичной СС: ";
	cin >> i;
	
	p = i;

	if (i >= 32768)
	{
		stepen = 1;
	}

	while (p > 0)
	{
		p % 10;
		p /= 10;
		stepen++;
	}

	foo(i, arr);

	for (int i = 0; i < stepen; i++)
	{
		m += arr[i] * pow(10, stepen - 1 - i);
	}
	cout << "Число " << i << " в " << 8 << " CC:  " << m;
	cout << endl << endl;
	system("pause");
}

