
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
    int Ar[200];
    int main(void) {

        srand(time(NULL));
        int i, k= 0;
        int j = 0;

        for (; ;j=0) {

            for (i = 0; i < 200; Ar[i++] = rand() % 100 - 50);
            printf("Array:\n");

            for (i = 0; i < 200; printf("%3d ", Ar[i++]));
            printf("\n");

            for (i = 0; i < 200; i++) {

                if (Ar[i] >= 0) k++;

                else if (Ar[i] < 0) k = 0;

                if (k > 7) j++;
            }

            printf("Count of positive sequences (i > 7) = %d", j);
            
            getchar();
            system("cls");
        }
        return 0;
    }


