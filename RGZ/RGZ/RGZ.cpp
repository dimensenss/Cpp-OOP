#include <iostream>
#include <conio.h>
#include <iomanip>
#include <chrono>

#define N 10//Элементов в массиве

using namespace std;
void first_sorting(int arr[], int n);
void second_sorting(int arr[], int n);
void ordered_array(int arr[], int n);
void reverse_array(int arr[], int n);
void disordered_array(int arr[], int n);
void dur_array(double dur_arr[], int M);
int main()
{
	int const M = 700; // Количество циклов
	setlocale(0, "rus");

	int arr[N];
	int reverse_arr[N];
	int disordered_arr[N];
	int disordered_arr_2[N];

	int temp;
	//Упорядоченый массив
	ordered_array(arr, N);
	//Вывод упорядоченого массива
	cout << "Упорядоченный массив :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	//Вызов первой функции
	first_sorting(arr, N);
	cout << endl << "Отсортированый уподорядоченый массив (1 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	//Вызов второй функции
	second_sorting(arr, N);
	cout << endl << "Отсортированый уподорядоченый массив (2 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}
	ordered_array(arr, N);
	cout << endl << endl << endl;

	//Обратный массив
	cout << "Обратный массив :";

	reverse_array(reverse_arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}

	//Вызов первой функции
	first_sorting(reverse_arr, N);
	cout << endl << "Отсортированый обратно уподорядоченый массив (1 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	//Возврат в обратный массив
	cout << endl << endl;
	cout << "Проверка заходимого массива :";
	reverse_array(reverse_arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}
	cout << endl;
	//Вызов второй функции
	second_sorting(reverse_arr, N);
	cout << endl << "Отсортированый обратно уподорядоченый массив (2 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}
	reverse_array(reverse_arr, N);
	cout << endl << endl << endl;

	cout << "Неупорядоченный массив :";

	disordered_array(disordered_arr, N);
	//Печать неупорядоченого массива
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr[i];
	}
	//Копия неупорядоченого массива

	for (int i = 0; i < N; i++)
	{
		disordered_arr_2[i] = disordered_arr[i];
	}

	//Вызов первой функции
	first_sorting(disordered_arr, N);
	cout << endl << "Отсортированый обратно уподорядоченый массив (1 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr[i];
	}
	//Печать для наглядности, что во вторую сортировку входит неупорядоченый массив
	cout << endl << endl;
	cout << "Проверка заходимого массива :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr_2[i];
	}
	cout << endl;
	//Вызов второй функции
	second_sorting(disordered_arr_2, N);
	cout << endl << "Отсортированый обратно уподорядоченый массив (2 сотривка) :";
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr_2[i];
	}
	cout << endl;
	disordered_array(disordered_arr, N);
	 
	//Подсчет времени
	double dur_arr[M];
	double aver_dur = 0;
	cout << endl;

	cout << "Упорядоченный массив" << endl; //1

	ordered_array(arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		ordered_array(arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		first_sorting(arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}
	dur_array(dur_arr, M);

	for (int i = 0; i < M; i++)
	{
		//std::cout << "Duration " << i << " = " << dur_arr[i] << "s" << endl;
		if (i >= 100 && i < 600)aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 1.1 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; // Обнуляем среднее значение
	ordered_array(arr, N); //Перезадаем массив

	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		ordered_array(arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		second_sorting(arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}

	dur_array(dur_arr, M); //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		//std::cout << "Duration " << i << " = " << dur_arr[i] << "s" << endl;
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 1.2 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; //Обнуляем среднее значение
	cout << endl << endl;


	cout << "Обратно упорядоченный массив" << endl;   //2

	reverse_array(reverse_arr, N);
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		reverse_array(reverse_arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		first_sorting(reverse_arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}

	dur_array(dur_arr, M); //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		//std::cout << "Duration " << i << " = " << dur_arr[i] << "s" << endl;
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 2.1 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; //Обнуляем среднее значение

	reverse_array(reverse_arr, N); //Перезадаем массив
	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << reverse_arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		reverse_array(reverse_arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		second_sorting(reverse_arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}

	dur_array(dur_arr, M); //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		//std::cout << "Duration " << i << " = " << dur_arr[i] << "s" << endl;
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 2.2 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; //Обнуляем среднее значение
	cout << endl << endl;


	cout << "Неупорядоченный массив" << endl; //3

	disordered_array(disordered_arr, N);

	for (int i = 0; i < N; i++)
	{
		cout << setw(4) << disordered_arr[i];
	}

	for (int i = 0; i < N; i++)  //Копия неупорядоченого массива
	{
		disordered_arr_2[i] = disordered_arr[i];
	}

	for (int i = 0; i < M; i++)
	{
		disordered_array(disordered_arr, N);
		auto start = std::chrono::high_resolution_clock::now();

		first_sorting(disordered_arr, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}
	dur_array(dur_arr, M); //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		//std::cout << "Duration " << i << " = " << dur_arr[i] << "s" << endl;
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 3.1 = %.8lf\n", aver_dur / 500);

	aver_dur = 0; //Обнуляем среднее значение

	for (int i = 0; i < N; i++) //Копия массива с которым мы заходим в функцию
	{
		cout << setw(4) << disordered_arr_2[i];
	}

	for (int i = 0; i < M; i++)
	{
		disordered_array(disordered_arr_2, N);
		auto start = std::chrono::high_resolution_clock::now();

		second_sorting(disordered_arr_2, N);									//первая/вторая сортировка     (какой массив в качестве параметра/ N)

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		dur_arr[i] = duration.count();
	}
	dur_array(dur_arr, M);  //Сортировка по убыванию подсчитаных значений времени

	for (int i = 0; i < M; i++)
	{
		//std::cout << "Duration " << i << " = " << dur_arr[i] << "s" << endl;
		if (i >= 100 && i < 600) aver_dur += dur_arr[i];
	}

	cout << "\t";
	printf("Duration 3.2 = %.8lf\n", aver_dur / 500);

	cout << endl << endl;
}

//Функция задающая упорядоченый массив
void ordered_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
}
//Функция задающая обратно упорядоченый массив
void reverse_array(int arr[], int n)
{
	int i;
	int k = n;
	for (int i = 0; i < n; i++, --k)
	{
		arr[i] = k;
	}
}
//Функция задающая неупорядоченый массив
void disordered_array(int arr[], int n)
{
	//srand(time(0));
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	for (int i = 0; i < n; i++)
	{
		swap(arr[i], arr[rand() % n]);

	}
}
//Четно-нечетная сортировка
void first_sorting(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int i1 = (i % 2) ? 0 : 1; i1 + 1 < n; i1 += 2) // (i % 2) ? 0 : 1, возвращает 1 если i четное, 0 - если i не четное
		{
			if (arr[i1] > arr[i1 + 1])
			{
				int temp = arr[i1];
				arr[i1] = arr[i1+1];
				arr[i1+1] = temp;
				//swap(arr[i1], arr[i1 + 1]);
			}
		}
	}
}
//Блинная сортировка
void second_sorting(int arr[], int n)
{
	int i_max;
	for (int i = n; i > 1; i--)
	{
		i_max = 0;
		//Находим максимальный элемент и переворачиваем массив
		for (int j = i - 1; j > 0; j--)
		{
			if (arr[j] > arr[i_max])
			{
				i_max = j;
			}
		}
		//если предыдущий элемент равен текущему - пропускаем 
		if (i_max == i - 1)
		{
			continue;
		}
		//переворот элементов массива от индекса j до индекса index.
		int index = i;
		for (int j = i_max; j < --index; j++)
		{
			int temp = arr[j];
			arr[j] = arr[index];
			arr[index] = temp;
			//swap(arr[j], arr[index]);
		}
	}
}
//Сортировка по убыванию подсчитаных значений времени
void dur_array(double dur_arr[], int M)
{
	for (int i = 0; i < M; i++)
	{
		for (int j = i + 1; j < M; j++)
		{
			if (dur_arr[i] < dur_arr[j])
			{
				int temp = dur_arr[i];
				dur_arr[i] = dur_arr[j];
				dur_arr[j] = temp;
				//swap(dur_arr[i], dur_arr[j]);
			}
		}
	}
}

