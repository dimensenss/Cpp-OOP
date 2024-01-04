#include "Header.h"


int main()
{
    int n, m, a;
    bool f = 0, f1 = 0;
    vector<Base*> base;
    Base ob;
    while (1) {
        system("cls");
        cout << "Fill array - 1\nPrint array - 2\nInput one object in file - 3\nOutput one object from file - 4\nInput all array in file - 5\nOutput all array from file - 6\n\n";
        cin >> n;
        switch (n) {
        case 1:
            system("cls");
            base = ob.input();
            f = 1;
            system("pause");
            break;
        case 2:
            system("cls");
            try {
                if (f)
                    ob.print(base);
                else
                    throw exception("Array doesnt create!");
            }
            catch (const exception& ex) {
                cout << ex.what() << "\n";
            }
            system("pause");
            break;
        case 3:
            system("cls");
            try {
                if (f) {
                    ob.print(base);
                    cout << "\nEnter num of object: ";
                    cin >> m;
                    if (m < 0 || m > base.size()) {
                        throw exception("Error, num < 0 or num > arr size");
                    }
                    ob.writeToFile(*base[m]);
                    f1 = 1;
                }
                else
                    throw exception("Array doesnt create!");
            }
            catch (const exception& ex) {
                cout << ex.what() << "\n";
            }
            system("pause");
            break;

        case 4:
            system("cls");
            try {
                if (f1) {
                    cout << "\nEnter num of object: ";
                    cin >> a;
                    if (a < 0) {
                        throw exception("Error, num < 0");
                    }
                    ob = ob.readFromFile(a);
                    ob.print();
                    
                }
                else
                    throw exception("Nothing was written to the file");
            }
            catch (const exception& ex) {
                cout << ex.what() << "\n";
            }
            system("pause");
            break;
        case 5:
            system("cls");
            try {
                if (f) {
                    for (int i = 0; i < base.size(); i++)
                        ob.writeToFile(*base[i]);

                }
                else
                    throw exception("Array doesnt create!");
            }
            catch (const exception& ex) {
                cout << ex.what() << "\n";
            }
            system("pause");
            break;
        case 6:
            system("cls");
            try {
                base = ob.readFromFileAll();
                f = 1;
                if(f)
                    ob.print(base);
                else
                    throw exception("Array doesnt create!");
            }
            catch (const exception& ex) {
                cout << ex.what() << "\n";
            }
            system("pause");
            break;

        }
    }
}
