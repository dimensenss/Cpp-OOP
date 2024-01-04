#include "foo.h"


void fill_array(int* arr, int size)
{
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *(arr + i * size + j) = rand() % 10;
        }
    }
}

void print_array(int* arr, int size) 
{
    
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout <<"     "<< *(arr + i * size + j);
        }
        cout << endl;
    }
}

void buble_sort(int* arr, int s)
{

    for (int a = 0; a < s; a++)
    {
        for (int b = 0; b < s; b++)
        {
            for (int i = 0; i < s; i++)
            {
                for (int j = 0; j < s; j++)
                {
                    if (*(arr + a * s + b) < *(arr + i *s + j))
                        swap(*(arr + a * s + b), *(arr + i * s + j));
                }
            }
        }
    }
}
void sort_array(int* arr, int size)
{
    int i, j, k, edge, num = (size * size)-1;
    int* arr2 = new int[size * size];
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(arr2 + i * size + j) = *(arr + i * size + j);
        }
    }
    int* ptr = arr2;
    
    for (k = 0; k < size / 2; k++) { //слои

        edge = size - 1 - k;
        
        
        for (i = edge; i > k; i--, num--)
            *(arr + i*size +k) = *(arr2 + num);

        for (j = k; j < edge; j++, num--)
            *(arr + k * size + j) = *(arr2 + num);

        for (i = k; i < edge; i++, num--)
            *(arr + i * size + edge) = *(arr2 + num);

        for (j = edge; j > k; j--, num--)
            *(arr + edge * size + j) = *(arr2 + num);
    }

    if (size % 2)
        *(arr + (size / 2) * size + (size / 2)) = *ptr;//центальный элемент

    for (i = 0; i < size; i++)
    {
        for (j = size - 1; j >= 0; j--) {
            printf("%6d", *(arr + i*size +j));
        }
        printf("\n");
    }
    
}

void alloc_matrix(int**& m, int size)
{
    m = new int* [size];
    for (int i = 0; i < size; i++)
    {
        *(m+i) = new int[size];
    }
}

void release_matrix(int**& m, int size)
{
    for (int i = 0; i < size; i++)
        delete[] * (m + i);

    delete[] m;
}

void fill_matrix(int** m, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            *(*(m + i) + j) = rand() % 100;
        }
    }
}
void print_matrix(int** m, int size) {
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout <<"    "<< *(*(m + i) + j);
        }
        cout << endl;
    }
}
void buble2_sort(int** m, int size)
{
    
    for (int a = 0; a < size; a++)
    {
        for (int b = 0; b < size; b++)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (*(*(m + a) + b) < *(*(m + i) + j))
                    {
                        int temp = *(*(m + a) + b);
                        *(*(m + a) + b) = *(*(m + i) + j);
                        *(*(m + i) + j) = temp;
                    }
                }
            }
        }
    }
}

void sort_matrix(int** m, int size)
{
    int i, j, k, edge, num = (size * size) - 1;
    int** m2 = nullptr;
    alloc_matrix(m2, size);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            *(*(m2+i)+j) = *(*(m + i) + j);
        }
    }
    int** ptr = m2;

    for (k = 0; k < size / 2; k++) { //слои

        edge = size - 1 - k;
        
        int b = edge;
        int z = 2;
        int h = 0;
        for (i = edge; i > k; i--)
            *(*(m + i) + k) = *(*(m2 + edge) + i);
        

        for (j = k; j < edge; j++, b--) {
            *(*(m + k) + j) = *(*(m2 + b) + h); 
            h = 2;
        }

        for (i = k, b = edge -1; i < edge; i++, num--)
            *(*(m+i)+edge) = *(*(m2 + b) + i);
        
        for (j = edge; j > k; j--, num--)
            *(*(m+edge)+j) = *(*(m2 + k) + j);
    }

    if (size % 2)
        *(*(m+size/2)+size/2) = **ptr;//центальный элемент

    for (i = 0; i < size; i++)
    {
        for (j = size - 1; j >= 0; j--) {
            printf("%6d", *(*(m+i)+j));
        }
        printf("\n");
    }

}
