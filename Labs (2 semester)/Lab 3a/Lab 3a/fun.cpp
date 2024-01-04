#include "fun.h"

void fill(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        *(arr + i) = rand() % 50-20;
    }
}

void print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
}

void print_menu()
{
    //system("cls");
    printf("Действия?\n");
    printf("1. относительный адрес\n");
    printf("2. через абсолютный адрес\n");
    printf("3. не использовать адресацию\n");
    printf("4. через массив указателей\n");
    printf("5. через указатель на указатель\n");
    printf("6. оформить в виде функции с параметрами указателями\n");
    printf("7. Выход\n");
    printf(">");
}

int get_variant() {
    int variant;
    cin >> variant;
    if (variant < 1 || variant > 7)
    {
        cout << "Введите число в диапозоне 1 - 7" << endl;
        return 0;
    }
    else
        return variant;
}
void foo(int* arr, int size, int* sum, int* count) {
    for (int i = 0; i < size; i++)
    {
        if (*arr < 0) {
            *sum += *arr;
            (*count)++;
        }
        arr++;
    }
}
