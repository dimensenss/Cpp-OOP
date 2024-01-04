#include "foo.h"

void print_menu()
{
	cout << "\n";
	printf("��������?\n");
	printf("1. ���������� �������\n");
	printf("2. ���������� ������ �� ����������� ��������� ��������\n");
	printf("3. ���������� ������ �� ������������ ��������� �����\n");
	printf("4. ���������� ����� �� ��\n");
	printf("5. ���������� ������������ �� ��\n");
	printf("6. �����\n");
	printf(">");
}

int get_variant() 
{
	int variant;
	cin >> variant;
	if (variant < 1 || variant > 6)
	{
		cout << "������� ����� � ��������� 1 - 6" << endl;
		return 0;
	}
	else
		return variant;
}

void alloc_matrix(int**& m, int s)
{
	m = new int* [s];
	for (int i = 0; i < s; i++)
	{
		*(m + i) = new int[s];
	}
}
void fill_matrix(int**& m, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			*(*(m + i) + j) = rand() % 100;
		}
	}
}

void print_matrix(int** m, int s)
{
	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			cout << *(*(m + i) + j) << "\t";
		}
		cout << "\n";
	}
}

void print_array(int* a, int s)
{

	for (int i = 0; i < s; i++)
	{
		cout << *(a + i) << "\t";
	}
}

void release_matrix(int**& m, int s)
{
	for (int i = 0; i < s; i++)
		delete[] * (m + i);

	delete[] m;
}

int*& foo(int**& m, int s, int* min_col, int* max_row, int* sum_gd, int* sum_pd)
{
	int* arr = new int[2];

	//min elements in cols
	for (int i = 0; i < s; i++)
	{
		*(min_col + i) = INT_MAX;
		for (int j = 0; j < s; j++)
		{
			if (*(*(m + j) + i) < *(min_col + i)) {
				*(min_col + i) = *(*(m + j) + i);
			}
		}
	}

	//max elemets in rows
	for (int i = 0; i < s; i++)
	{
		*(max_row + i) = INT_MIN;
		for (int j = 0; j < s; j++)
		{
			if (*(*(m + i) + j) > *(max_row + i)) {
				*(max_row + i) = *(*(m + i) + j);
			}
		}
	}

	for (int i = 0; i < s; i++)
	{
		for (int j = 0; j < s; j++)
		{
			if (i == j)
				*sum_gd += *(*(m + i) + j);
			if (i == s - j- 1)
				*sum_pd *= *(*(m + i) + j);
		}
	}
	
	*arr = *sum_gd;
	*(arr + 1) = *sum_pd;
	
	return *&arr;
}