

#include "Header.h"
int main()
{
    srand(time(0));

    int arr1 [5];
    for (int i = 0; i < 5; i++)
        arr1[i] = rand() % 4+2;
    int arr2[5];
    for (int i = 0; i < 5; i++)
        arr2[i] = rand() % 4 + 2;
    int arr3[5];
    for (int i = 0; i < 5; i++)
        arr3[i] = rand() % 4 + 2;

    /*Prepod ob1("Galina Ivanovna Ivanova",55,"OOP", 1);
    Student ob2("Irina Vladimirovma", 18, arr);
    Zav_Kaf ob3("Maksin Olegovich", 47, "C++", 2, "Professor");
    ob1.print();
    cout << ob1.ask() << "\n";
    cout << ob1.who() << "\n\n";
    ob2.print();
    cout << ob2.ask() << "\n";
    cout << ob2.who() << "\n\n";
    ob3.print();
    cout << ob3.ask() << "\n";
    cout << ob3.who() << "\n\n";*/

    
    vector<Persona*> Shtat;
    Shtat.push_back(new Prepod ("Galina Ivanovna Ivanova", 55, "OOP", 1));
    Shtat.push_back(new Prepod("Sergey Nikolayovich Sudak", 35, "Python", 1));
    Shtat.push_back(new Student("Irina Vladimirovma Avtenuk", 18, arr1));
    Shtat.push_back(new Student("Dmitriy Alexandrovich Gnom", 19, arr2));
    Shtat.push_back(new Student("Andrey Fedorovich Melnichuk", 20, arr3));
    Shtat.push_back(new Zav_Kaf("Maksin Olegovich", 47, "C++", 2, "Professor"));
    for (int i = 0; i < Shtat.size(); i++)
    {
        Shtat[i]->print();
        cout << "\n";
    }
    Vuz ob;
    cout << "\n\n\n\n";
    ob.age_under_50(Shtat);
    cout << "\n";
    ob.borg(Shtat);
}
