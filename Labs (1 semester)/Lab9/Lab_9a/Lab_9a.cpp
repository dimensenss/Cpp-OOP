
#include <iostream>
#include <time.h>
#include <iomanip>
#include <cstdlib >
using namespace std;
int main()
{
	setlocale(0, "rus");
	srand(time(0));
	const int N = 100, M = 100;
	int Matrix[N][M];
	int string, col;
	int w = 4;
	int answer;
	while (true)
	{
		cout << "В чем состоит задача?" << endl;
		cout << "Задать матрицу и макс елемент переставить в начало(1)" << endl;
		cout << "Задать матрицу и мин елемент переставить в конец(2)" << endl;
		cout << "Выйти из программы (0)" << endl;
		cin >> answer;

		if (answer == 1)
		{
			cout << "Введите кол-во строк (1-100): ";
			cin >> string;
			if (string > 100 || string < 1)

			{
				cout << endl;
				cout << "Введите значение кол-во строк в диапозоне (1-100)";
				return 0;
			}

			cout << "Введите кол-во столбцов (1-100): ";
			cin >> col;
			if (col > 100 || col < 1)

			{
				cout << endl;
				cout << "Введите значение кол-во столбцов в диапозоне (1-100)";
				return 0;
			}

			for (int i = 0; i < string; i++)
			{

				if (i % string)
					cout << endl;
				for (int j = 0; j < col; j++)
				{
					Matrix[i][j] = rand() % 100;
					cout << setw(w) << Matrix[i][j];
				}
			}
			int max_string;
			//int temp;
			for (int i = 0; i < col; i++)
			{
				max_string = 0;

				for (int j = 1; j < string; j++)
				{
					if (Matrix[i][j] > Matrix[i][max_string])
					{
						max_string = j;
					}
				}
				/*temp = Matrix[i][0];
				Matrix[i][0] = Matrix[i][max_string];
				Matrix[i][max_string] = temp;*/
				swap(Matrix[i][0], Matrix[i][max_string]);
			}
			cout << endl;
			cout << "Перераспределенная матрица" << endl;
			for (int i = 0; i < string; i++)
			{
				for (int j = 0; j < col - 1; j++)
				{
					cout << setw(w) << Matrix[i][j];
				}
				cout << setw(w) << Matrix[i][col - 1] << endl;;
			}
			cout << endl;
		}

		if (answer == 2)
		{
			cout << "Введите кол-во строк (1-100): ";
			cin >> string;
			if (string > 100 || string < 1)

			{
				cout << endl;
				cout << "Введите значение кол-во строк в диапозоне (1-100)";
				return 0;
			}

			cout << "Введите кол-во столбцов (1-100): ";
			cin >> col;
			if (col > 100 || col < 1)

			{
				cout << endl;
				cout << "Введите значение кол-во столбцов в диапозоне (1-100)";
				return 0;
			}

			for (int i = 0; i < string; i++)
			{

				if (i % string)
					cout << endl;
				for (int j = 0; j < col; j++)
				{
					Matrix[i][j] = rand() % 100;
					cout << setw(w) << Matrix[i][j];
				}
			}
			int min_col;
			//int temp;
			for (int j = 0; j < string; j++)
			{

				min_col = 0;
				for (int i = 1; i < col; i++)
				{


					if (Matrix[i][j] < Matrix[min_col][j])
					{
						min_col = i;
					}
				}
				/*temp = Matrix[0][j];
				Matrix[0][j] = Matrix[min_col][j];
				Matrix[min_col][j] = temp;*/

				swap(Matrix[string-1][j], Matrix[min_col][j]);
			}
			cout << endl;
			cout << "Перераспределенная матрица" << endl;
			for (int i = 0; i < string; i++)
			{
				for (int j = 0; j < col - 1; j++)
				{
					cout << setw(w) << Matrix[i][j];
				}
				cout << setw(w) << Matrix[i][col - 1] << endl;;
			}
			cout << endl;
		}

		if (answer == 0)
		{
			cout << endl;
			cout << "Выход из программы, нажмите любую клавишу..." << endl;
			cout << endl << endl;
			return 0;
		}
	}
}


