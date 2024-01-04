#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	double a, b, c;
	double D;
	double x1, x2;
	while (1) {
		printf("Введите значение a >");
		scanf_s("%lf", &a);

		printf("Введите значение b >");
		scanf_s("%lf", &b);

		printf("Введите значение c >");
		scanf_s("%lf", &c);
		printf("\n\n\n");

		D = b * b - 4 * a * c;

		if (a == 0) {
			printf("Впишите значение a > 0\n\n");

			printf("Нажмите на любую кнопку...\n");
			_getch();
			system("cls");
		}

		if (D > 0 && a != 0)
		{
			x1 = ((-b) + sqrt(D)) / (2 * a);
			x2 = ((-b) - sqrt(D)) / (2 * a);

			printf("\tСуществует два корня :)\n\n");

			printf("x1 = %lf\n", x1);
			printf("x2 = %lf\n", x2);

			printf("Нажмите на любую кнопку...\n");
			_getch();
			system("cls");

		}
		else if (D == 0 && a != 0) {
			x1 = ((-b) + sqrt(D)) / (2 * a);

			printf("\tСуществует один корень :)\n\n");

			printf("x1 = %lf\n", x1);

			printf("Нажмите на любую кнопку...\n");
			_getch();
			system("cls");
		}

		else if (a!= 0) {
			printf("\nДискриминант меньше нуля\n\n");
			printf("\tКорней нет :(\n\n");

			printf("Нажмите на любую кнопку...\n");
			_getch();
			system("cls");
		}

			

	}
}

