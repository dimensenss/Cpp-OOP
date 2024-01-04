#include <stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS



int main()
{
    setlocale(LC_ALL, "ru");

    double x, y;
    while (1) {
        printf("Введите значение x >\n");
        scanf_s("%lf", &x);

        printf("Введите значение y >\n");
        scanf_s("%lf", &y);

        printf("x=%6.3lf;  y=%6.3lf\n", x, y);


        if (((x * x + y * y) <= 1 && y <= 0 && x <= 0) || (x >= 0 && x <= 1 && y >= 0 && y <= 1))
            printf("Точка попадает в область\n");
        else
            printf("Точка не попадает в область\n");
    }

}