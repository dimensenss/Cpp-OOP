
#include <iostream>
#include <time.h>
#include <iomanip>
#include <cstdlib>
using namespace std;
	void array_fill(int arr[100][100], int row, int col)
{
	srand(time(NULL));
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j= 0; j < col; j++)
		{
			if (rand() % 2)
			{
				arr[i][j] = rand() % 100;
			}
			else
			{
				arr[i][j] = rand() % 100 * (-1);
			}
		}
	}
}
void array_print(int arr[100][100], int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}
}
int array_sort(int arr[100][100], int col, int k)
{
	
	int w = 0;
	for (size_t i = 0; i < col; i++)
	{
			if (arr[k][i] >= 0)
			{
				w++;
			}
	}
	return w;
}
int main()
{
	setlocale(0, "rus");
	int row, col, k;
	const int N = 100, M = 100;
	int arr[N][M];

	cout << "Введите кол-во строк матрицы" << endl;
	cin >> row;
	cout << "Введите кол-во столбцов матрицы"<< endl;
	cin >> col;

	array_fill(arr, row, col);
	array_print(arr, row, col);
	cout << endl;
	int result;
	for (int i = 0; i < row; i++)
	{
	
		cout << "В  " << i + 1 << " строке " << array_sort(arr, col, i) << " положительных " << "элементов" << endl;
	}
}
