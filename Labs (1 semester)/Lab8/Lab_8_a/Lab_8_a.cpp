#include <iostream>
#include <iomanip>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;


int main() {
    setlocale(LC_ALL, "Russian");

    int i;
    const int N = 10;
    int places[N]{};
    int answer;

    for (int k = 0; k < 10; ) { 
        cout << "Вы курите?" << endl << "да-1/нет-0" << endl;

        cin >> answer;
        
        if (answer == 1 || answer == 0) {
            if (answer == 1) {
                for (int i = 0; i < 5; i++)
                {
                    if (places[i] == 0)
                    {
                        places[i] = 1;
                        cout << "Номер вашего места: " << i + 1 << endl << endl;
                        k++;
                        break;
                    }

                    if (i == 4 && places[i] == 1) {
                        cout << "В 1 отделе места закончились" << endl;
                    }
                }
            }
          
            if (answer == 0) {
                for (int i = 5; i < 10; i++) {

                    if (places[i] == 0)
                    {
                        places[i] = 1;
                        cout << "Номер вашего места: " << i + 1 << endl;;
                        k++;
                        break;
                    }

                    if (i == 9 && places[i] == 1)
                    {
                        cout << "К сожалению, места в этом отделе заняты" << endl;
                    }
                }
            }
        }
        else 
            cout << "Вы ввели некоректный ответ" << endl;
    }
            cout << endl<<"Все места заняты. Взлетаем!" << endl;
}