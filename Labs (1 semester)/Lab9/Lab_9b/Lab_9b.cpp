#include <iostream>
#include <time.h>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main()
{
	setlocale(0, "rus");
	srand(time(0));
	const int N = 100, M = 100;
	int Matrix[N][M];
	int Matrix_2[N][M];
	int string, col, string_2, col_2;
	int w = 4;

	while (true)
	{
		//задаем 1 матрицу
		cout << "Введите кол-во строк первой матрицы (1-100): ";
		cin >> string;

		if (string > 100 || string < 1)

		{
			cout << endl;
			cout << "Введите значение кол-во строк в диапозоне (1-100)";
			return 0;
		}//условие что кол-во строк в диапозоне

		cout << "Введите кол-во столбцов первой матрицы (1-100): ";
		cin >> col;

		if (col > 100 || col < 1)

		{
			cout << endl;
			cout << "Введите значение кол-во столбцов в диапозоне (1-100)";
			return 0;
		}//условие что кол-во столбцов в диапозоне



		cout << endl;

		//печатаем 1 матрицу со случайними значениями
		for (int i = 0; i < string; i++)
		{

			if (i % string)
				cout << endl;
			for (int j = 0; j < col; j++)
			{
				Matrix[i][j] = rand() % 10;
				cout << setw(w) << Matrix[i][j];
			}
		}

		cout << endl;

		cout << endl;
		//задаем 2 матрицу
		cout << "Введите кол-во строк второй матрицы (1-100): ";

		cin >> string_2;
		if (string_2 > 100 || string_2 < 1)

		{
			cout << endl;
			cout << "Введите значение кол-во строк в диапозоне (1-100)";
			return 0;
		}//условие что кол-во строк в диапозоне


		cout << "Введите кол-во столбцов второй матрицы (1-100): ";
		cin >> col_2;

		if (col_2 > 100 || col_2 < 1)

		{
			cout << endl;
			cout << "Введите значение кол-во столбцов в диапозоне (1-100)";
			return 0;
		}//условие что кол-во столбцов в диапозоне


		cout << endl;

		//печатаем 2 матрицу со случайними значениями
		for (int k = 0; k < string_2; k++)
		{

			if (k % string_2)
				cout << endl;
			for (int l = 0; l < col_2; l++)
			{
				Matrix_2[k][l] = rand() % 10;
				cout << setw(w) << Matrix_2[k][l];
			}
		}

		cout << endl;

		if (col == string_2)
		{
			cout << endl;
			cout << "Матрицы можно умножать!" << endl;
			cout << endl;
			cout << endl;
			cout << "Перемноженная матрица:" << endl;
			cout << endl;
			int product[N][M]{};

			for (int i = 0; i < string; i++)
			{
				for (int j = 0; j < col_2; j++)
				{
					for (int p = 0; p < col; p++)
					{
						product[i][j] += Matrix[i][p] * Matrix_2[p][j];
					}
					cout << setw(w) << product[i][j];
				}
				cout << endl;
			}
			cout << endl;
		}
		else
		{
			cout << endl;
			cout << "Кол-во столбцов 1 матрицы не совпадает с кол-во строк 2 матрицы" << endl;
			cout << endl;
			continue;
		}
	}
}
