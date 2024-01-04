#include <stdio.h>
#include <math.h>
#include <iostream>

int main(void) {
    setlocale(LC_ALL, "RUS");
    long n;
    double dbln;
    double sum = 0;
    double an;
    const double eps = 0.000001;
    double k1 = 1;



    for (n = 0; ; n++, k1 = -k1) {

        dbln = n;

        an = k1 * 1 / (2 * (n + 1));
       
        if (fabs(an) >= eps)

            sum += an;

        else break;

        if (n == 9)
            printf("Сумма 10 членов ряда = %10.7lf\n", sum);
    }

    printf("Полная сумма ряда = %10.7lf\n", sum);
    return 0;
}

