#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
int main(void)
{
    setlocale(LC_ALL, "ru");
    double a = 5;
    double t1, t2;
    double x;
    double ax, ab;
    double b;
    while (1) {
        printf("\n");
        printf("Ведите значение x (1;4) >\t");
        scanf("%lf", &x);
        printf("Введите значение b (5;10) >\t");
        scanf("%lf", &b);

        ax = a * x;
        ab = a * b;

        if (x <= 4 & b >= 5) {
            t1 = 1 / (6 * pow(a, 3)) * log((a + x) / (a - x)) + 1 / (2 * pow(a, 3));
            printf("t1=%lg\n", t1);

            t2 = (1 / ab) * log(tan(ax + b) / tan(ax - b));
            printf("t2=%lg\n", t2);
        }
        else {
            printf("EROR!\n");
            printf("Введите значение x или y в пределах\n");
        }

    }
        

        /*t1 = 1 / (6 * pow(a, 3)) * log((a + x) / (a - x)) + 1 / (2 * pow(a, 3));
        printf("t1=%lg\n", t1);*/
       /* if (x <= 4) {
            
        }
        else {
            printf("Введите значение x в пределах(-inf;4)\n");
        }
    */
    

   
        
}
