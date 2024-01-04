
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");

	int grib;
	while (1) {
		system("cls");
		printf("\t***Склонение слова гриб в зависимости от числа***\n");
		printf("Введите количество грибов >");
		scanf("%d", &grib);

		if ((grib % 100) >= 11 && (grib % 100) <= 19)
			printf("У меня %d грибов", grib);

		else if (grib % 10 >= 2 && grib % 10 <= 4)
			printf("У меня %d гриба", grib);

		else if (grib % 10 == 1)
			printf("У меня %d гриб", grib);

		else if (grib % 10 >= 5 && grib % 10 <= 9 || grib % 10 == 0)
			printf("У меня %d грибов", grib);

		else
			printf("Ошибка, введите положительное число!");




		printf("\n\n\n\n\n");
		printf("Введите любую клавишу для продолжения");
		_getch();
	}

	return 0;
}