#include "foo.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	while (true) 
	{
		HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
		char S[80];
		char S1[80];

		int num = 0;
		int amount = 0;
		int count = 0;
		system("cls");

		cout << "Enter string: " << endl;
		//cin.getline(S, 80);
		gets_s(S, 80);
		if (strlen(S) < 1) 
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			cout << "\nThe string must contain at least one character" << endl;
			system("pause");
			continue;
		}

		counter(S, &count);

		cout << "Enter the ordinal number of the word ->";
		cin >> num;
		if (num > count)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			cout << "\nThe selected word is not in the list\n";
			system("pause");
			cin.ignore();
			continue;
		}
		
		cout << "Enter amount of words ->";
		cin >> amount;

		if (amount > count - num + 1)
		{
			HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			cout << "\nThere are no so many words after the chosen\n";
			system("pause");
			cin.ignore();
			continue;
		}

		foo(S, S1, num, amount);

		puts(S1);
		
		cin.ignore();
		system("pause");
	}
	return 0;
}