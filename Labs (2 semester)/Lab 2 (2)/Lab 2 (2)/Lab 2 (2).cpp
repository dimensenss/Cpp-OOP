#include "fun.h"

table arr[10];

void menu()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    int N;
    int variant;
    do
    {
        print_menu();
        variant = get_variant();
        switch (variant)
        {
        case 1:
        {
            cout << "Сколько строк заполнять? --> ";
            cin >> N;
            input(N, arr);
        }break;

        /*case 2:
        {
            cout << "Сколько строк заполнять? --> ";
            cin >> N;
            random(N, arr);
        }break;*/

        case 3:
        {
            sort(N, arr);
        }break;

        case 4:
        {
            print(N, arr);
        }break;
        }
        if (variant != 5)
        {
            system("pause");
        }
    } while (variant != 5);
}


int main()
{
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
   
    menu();
    
    return 0;
}