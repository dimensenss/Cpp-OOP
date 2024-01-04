#include "foo.h"

//#define ARRAY

int main(void)
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int size;
        
#ifdef ARRAY
    cout << "Введите размерность массива > ";
    cin >> size;
    if (size <= 0 || size > 10)
    {
        cout << "Введите значение от 1 до 10";
    }
    
    int* arr = new int[size * size];

    fill_array(arr, size);
    cout << "Изначальный одномерный массив\n";
    print_array(arr, size);
    buble_sort(arr, size);
    cout << "\n";
    
    cout << "\n";
    cout << "Массив по заднию\n";
    sort_array(arr, size);
    cout << "\n\n";
    

    cout << "\n\n";

    

    delete[]arr, arr = nullptr;

#else
    int size2;
    

    cout << "Введите количество  > ";
    cin >> size2;

    int** matrix = nullptr;
    
    alloc_matrix(matrix, size2);

    fill_matrix(matrix, size2);
    cout << "Изначальная матрица\n";
    print_matrix(matrix, size2);

    buble2_sort(matrix, size2);
    cout << "\n\n";
    
    cout << "Матрица по заднию\n";
    sort_matrix(matrix, size2);

    release_matrix(matrix, size2);
#endif

}