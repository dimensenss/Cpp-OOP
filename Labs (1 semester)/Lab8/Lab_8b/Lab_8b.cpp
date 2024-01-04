//#include <iostream>
//#include <windows.h>
//#include <iomanip>
//using namespace std;
//
//int main() {
//
//    int arr_size;
//    cout << "Put the count of elements in array" << endl;
//    cin >> arr_size;
//
//    int arr[100]{};
//    int answer;
//
//    for (int i = 0; i < arr_size; i++)
//    {
//        arr[i] = i + 1;
//
//        cout << arr[i] << setw(3);
//    }
//
//    cout << endl << endl;
//
//    while (true) {
//
//        cout << "\nWhat you wanna do with array?" << endl;
//        cout << "Insert elements(1)" << endl;
//        cout << "Delete elemets(2)" << endl;
//        cout << "Exit(0)" << endl;
//
//        cin >> answer;
//
//        if (answer == 0) {
//
//            cout << "\nPush any key to exit...." << endl << endl;
//            break;
//        }
//
//        int new_arr, new_el, new_size;
//        int answer_add, amount_el_add;
//        int el_add = 0;
//        if (answer == 1) {
//
//            cout << "Put the element which you wanna add" << endl;
//            cin >> answer_add;
//
//            cout << "Put count of elements which you wanna add" << endl;
//            cin >> amount_el_add;
//
//            cout << "Put number of element starting from which we will add" << endl;
//            cin >> el_add;
//
//            int new_arr[100];
//            amount_el_add = abs(amount_el_add);
//
//            for (int i = 0; i < 100; i++)
//            {
//                new_arr[i] = arr[i];
//            }
//            arr_size += amount_el_add;
//
//            el_add--;
//            int end_el = el_add + amount_el_add; //element which you wanna add + count of these elements
//            int j = 0;
//            for (int i = 0; i < 100; i++)
//            {
//                if (i >= el_add && i < end_el)
//                {
//                    arr[i] = answer_add;
//                }
//                else
//                {
//                    arr[i] = new_arr[j];
//                    j++;
//                }
//            }
//
//
//            cout << endl << "Our new Massive" << endl;
//
//            for (int new_i = 0; new_i < arr_size; new_i++)
//            {
//                cout << setw(3) << arr[new_i];
//
//            }
//
//            cout << endl << endl;
//        }
//
//        int amount_el, el, i;
//
//        if (answer == 2) {
//
//            cout << "\nPut the count of elements, which you wanna delete\n";
//            cin >> amount_el;
//            amount_el = abs(amount_el);
//
//            cout << "Put number of element starting from which we will delete (1 to 10) " << amount_el << " \n";
//            cin >> el;
//            el = abs(el);
//            if (el > 10)
//            {
//                cout << "Eror, these element doesnt exist\n\n";
//            }
//            else
//            {
//                if (amount_el > 10 || amount_el == 0)
//                {
//                    cout << "Put the count of elements which you wanna delete 1 to 10\n\n";
//                }
//                else
//                {
//                    el -= 1;
//                    for (i = el; i < el + amount_el; i++)
//                    {
//                        arr[i] = 0;
//                    }
//                    for (i = 0; i < arr_size; i++)
//                    {
//                        if (arr[i] != 0)
//                        {
//                            cout << arr[i] << setw(3);
//                        }
//                    }
//                    cout << "\n\n";
//                }
//            }
//        }
//    }
//}
//
#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

#include <iostream>
#include <windows.h>
#include <iomanip>
using namespace std;

int main() {

    int arr_size;
    cout << "Put the count of elements in array" << endl;
    cin >> arr_size;

    int arr[100]{};
    int answer;

    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = i + 1;

        cout << arr[i] << setw(3);
    }

    cout << endl << endl;

    while (true) {

        cout << "\nWhat you wanna do with array?" << endl;
        cout << "Insert elements(1)" << endl;
        cout << "Delete elemets(2)" << endl;
        cout << "Exit(0)" << endl;

        cin >> answer;

        if (answer == 0) {

            cout << "\nPush any key to exit...." << endl << endl;
            break;
        }

        int new_arr, new_el, new_size;
        int answer_add, amount_el_add;
        int el_add = 0;
        if (answer == 1) {

            cout << "Put the element which you wanna add" << endl;
            cin >> answer_add;

            cout << "Put count of elements which you wanna add" << endl;
            cin >> amount_el_add;

            cout << "Put number of element starting from which we will add" << endl;
            cin >> el_add;

            int new_arr[100];
            amount_el_add = abs(amount_el_add);

            for (int i = 0; i < 100; i++)
            {
                new_arr[i] = arr[i];
            }
            arr_size += amount_el_add;

            el_add--;
            int end_el = el_add + amount_el_add; //element which you wanna add + count of these elements
            int j = 0;
            for (int i = 0; i < 100; i++)
            {
                if (i >= el_add && i < end_el)
                {
                    arr[i] = answer_add;
                }
                else
                {
                    arr[i] = new_arr[j];
                    j++;
                }
            }


            cout << endl << "Our new Massive" << endl;

            for (int new_i = 0; new_i < arr_size; new_i++)
            {
                cout << setw(3) << arr[new_i];

            }

            cout << endl << endl;
        }

        int amount_el, el, i;

        if (answer == 2) {

            cout << "\nPut the count of elements, which you wanna delete\n";
            cin >> amount_el;
            amount_el = abs(amount_el);

            cout << "Put number of element starting from which we will delete (1 to 10) " << amount_el << " \n";
            cin >> el;
            el = abs(el);
            if (el > 10)
            {
                cout << "Eror, these element doesnt exist\n\n";
            }
            else
            {
                if (amount_el > 10 || amount_el == 0)
                {
                    cout << "Put the count of elements which you wanna delete 1 to 10\n\n";
                }
                else
                {
                    el -= 1;
                    for (i = el; i < el + amount_el; i++)
                    {
                        arr[i] = 0;
                    }
                    for (i = 0; i < arr_size; i++)
                    {
                        if (arr[i] != 0)
                        {
                            cout << arr[i] << setw(3);
                        }
                    }
                    cout << "\n\n";
                }
            }
        }
    }
}
