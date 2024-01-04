
#include "foo.h"

int main()
{
    //SetConsoleCP(1251);
    //SetConsoleOutputCP(1251);
    srand(time(0));

    int SIZE, variant;
    cout << "Put size of matrix > ";
    cin >> SIZE;
    system("cls");

    int** matrix = nullptr;
    int(*foo_ptr)(int**&, int);
    alloc_matrix(matrix, SIZE);
    do
    {
        print_menu();
        variant = get_variant();

        switch (variant)
        {
        case 1: {
            system("cls");
            cout << "\n";
            fill_matrix(matrix, SIZE);
            print_matrix(matrix, SIZE);
            cout << "\n";
        }break;
        case 2:
        {
            system("cls");
            cout << "\n";
            print_matrix(matrix, SIZE);
            cout << "\n\n";
            foo_ptr = first_foo;
            cout << "Sum = " << foo_ptr(matrix, SIZE);
            cout << "\n\n";
        }break;
        case 3:
        {
            system("cls");
            cout << "\n";
            print_matrix(matrix, SIZE);
            cout << "\n\n";
            foo_ptr = second_foo;
            cout << "Multiplication = " << foo_ptr(matrix, SIZE);
            cout << "\n\n";
        }break;
              
        }
    } while (variant != 4);
    release_matrix(matrix, SIZE);
}

