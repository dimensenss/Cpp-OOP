#include "fun.h"

void fill(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(arr + i) = rand() % 45;
	}

}

void print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << "\t";
	}
}

void sort(int* arr, int size)
{
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (*(arr + j) > *(arr + j + 1)) {
				temp = *(arr + j);
				*(arr + j) = *(arr + j + 1);
				*(arr + j + 1) = temp;
			}
		}
	}
}

void barr(int* arr, int* brr)
{

	for (int i = 0; i < 3; i++)
	{
		*(brr + i) = *(arr + i);
	}
}