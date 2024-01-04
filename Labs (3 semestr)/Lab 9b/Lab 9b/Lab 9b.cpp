#include "Header.h">

int main()
{
    map <Name, Number> ::iterator it;
    map <Name, Number> ::iterator jt;
    map <Name, Number> map1;
    map <Name, Number, Name> map2;

    string names[5] = { "Petya", "Dima", "Andrey", "Ira", "Anton" };
    string last_names[5] = { "Ivanov", "Asnas", "Boba", "Tkach", "Intonov" };
    int numbers[5]{ 947253824 ,432565466 ,414646677 ,414646677 ,86432824 };
    int n = 0;
    string s;
    char c,c1;

    do {
        system("cls");
        cout << "\n1 - Create map\n2 - Print\n3 - Print by name\n4 - Print by letter in last name\n5 - Del by letter in last name\n6 - Sort by last name\n0 - Exit\n> ";
        cin >> n;
        switch (n)
        {
        case 1:
            for (int i = 0; i < 5; i++) {
                map1.insert({ Name(names[i], last_names[i]), Number(numbers[i]) });
            }
            cout << "\n";
            break;
        case 2:
            cout << "\n";
            for (auto p = begin(map1); p != end(map1); p++)
                cout << p->first << p->second;
            cout << "\n";
            system("pause");
            break;
        case 3:
            cout << "\n";
            for (auto p = begin(map1); p != end(map1); p++)
                cout << p->first << p->second;
            cout << "\n";
            cout << "Enter name: ";
            cin >> s;
            cout << "\n";
            for (auto p = begin(map1); p != end(map1); p++) {
                if (((Name&)p->first).get_name() == s)
                    cout << p->first << p->second;
            }
            cout << "\n";
            system("pause");
            break;
        case 4:
            cout << "\n";
            for (auto p = begin(map1); p != end(map1); p++)
                cout << p->first << p->second;
            cout << "\n";
            cout << "Enter char: ";
            cin >> c;
            for (auto p = begin(map1); p != end(map1); p++) {
                if (((Name&)p->first).get_last_name()[0] == c)
                    cout << p->first << p->second;
            }
            cout << "\n";
            system("pause");
            break;
        case 5:
            for (auto p = begin(map1); p != end(map1); p++)
                cout << p->first << p->second;
            cout << "\n";
            cout << "Enter char: ";
            cin >> c1;
            for (it = map1.begin(); it != map1.end();) {
                jt = it;
                it++;
                if (((Name&)jt->first).get_last_name()[0] == c1) {
                    cout << "Deleting: " << (*jt).first << endl;
                    map1.erase(jt);
                }
            }
            cout << "\n";
            system("pause");
            break;
        case 6:
            cout << "\n";
            for (int i = 0; i < 5; i++) {
                map2.insert({ Name(names[i], last_names[i]), Number(numbers[i]) });
            }
            for (auto p = begin(map2); p != end(map2); p++)
                cout << p->first << p->second;
            cout << "\n";
            system("pause");
            break;

        }
    } while (n != 0);
}
