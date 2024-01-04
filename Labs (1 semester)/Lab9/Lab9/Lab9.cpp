#include <stdio.h>
#include <iostream>
#include <iomanip>
#define N 9
using namespace std;

int main(){

    int arr[N][N];

    int i, j, k, edge, num = N * N;

    for (k = 0; k < N / 2; k++) { //слои

        edge = N - 1 - k;

        for (i = edge; i > k; i--, num--)
            arr[i][k] = num;

        for (j = k; j < edge; j++, num--)
            arr[k][j] = num;

        for (i = k; i < edge; i++, num--)
            arr[i][edge] = num;

        for (j = edge; j > k; j--, num--)
            arr[edge][j] = num;
    }

    if (N % 2) 
        arr[N/2][N/2] = num; //центальный элемент

     for (i = 0; i < N; i++){

            for (j = N - 1; j >= 0; j--) {

                cout << setw(6) << arr[i][j];
            }
        cout << endl;
     }
    return 0;
}
