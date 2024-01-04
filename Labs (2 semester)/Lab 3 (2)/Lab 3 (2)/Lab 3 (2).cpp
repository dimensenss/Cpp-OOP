#include "fun.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	int size;
	bool answer = true;
	do {


		cout << "Введите размер массива в диапозоне 1-100 " << endl;
		cin >> size;
		if (size < 1 || size>100) cout << "Введите размер в диапозоне 1-100";
		system("cls");

		int* arr = new int[size];
		int* brr = new int[3];

		fill(arr, size);
		cout << "Первый массив" << endl;
		print(arr, size);
		sort(arr, size);

		cout << "\n\n\n";

		cout << "Отсортированый первый массив" << endl;
		print(arr, size); //output sort arr

		cout << "\n\n\n";

		barr(arr, brr); // fill brr
		cout << "Массив из первых трёх минимальных элементов" << endl;
		print(brr, 3);

		cout << "\n\n\n";

		cout << "Выполнять программу дальше, введите - 1" << endl << "Выйти из программы, введите - 0 " << endl;
		cin >> answer;
		system("pause");
		system("cls");

		delete[] arr;
		delete[] brr;
	} while (answer != false);

	return 0;
}