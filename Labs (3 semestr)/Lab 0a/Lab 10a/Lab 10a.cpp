#include <iostream>
#include <conio.h>
using namespace std;

class figure{
public:	
    int Inc(int a = 2, int b = 0)
    {
        if (a == 0)
            return b * b;
        if (b == 0)
            return a * a;
    return a * b;
    }
};

int main()
{
    figure area;
    int a;
    do {
        cout << "Square - 1\nRectangle - 2\n";
   
        cin >> a;
        if (a == 1) {
            cout << "Enter length side >";
            int b;
            cin >> b;
            if (b > 0)
                cout << "Figure area = " << area.Inc(b) << "\n\n\n";
            else {
                
                cout << "Eror, try one more time\n";
                cin.clear();
                cin.ignore(32767, '\n');
                system("pause");
                system("cls");
                continue;
            }
        }
        else if (a == 2) {
            cout << "Enter length a,b sides >";
            int n, m;
            cin >> n >> m;
            if (n > 0 && m > 0) {
                cout << "Figure area = " << area.Inc(n, m) << "\n\n\n";
            }
            else {
                cout << "Eror, try one more time\n";
                cin.clear();
                cin.ignore(32767, '\n');
                system("pause");
                system("cls");
                continue;
            }
        }
        else {
            cout << "Eror\n";
            cin.clear();
            cin.ignore(32767, '\n');
            system("pause");
            system("cls");
            continue;
        }
        cout << "Press any key to continue . . .\n";
        puts("Press 'esc' to exit . . .");
    } while (_getch() != 27);
}