#include "Header.h"

int main()
{
	//master FirstMaster;
	/*master SecondMaster;

	dog* FirstMasterDogs = new dog[2];
	FirstMasterDogs[0].SetDogsMerit("Tobik", 7, 4);
	FirstMasterDogs[1].SetDogsMerit("Bim", 10, 17);

	FirstMaster.SetMastersMerit("Dmitriy", FirstMasterDogs);
	FirstMaster.GetMastersMerit();
	cout << "Dmitriy`s dogs:\n\n";
	FirstMasterDogs[0].GetDogsMerit();
	cout<<"\n";
	FirstMasterDogs[1].GetDogsMerit(); 

	cout << "------------------------------------\n";
	dog* SecondMasterDogs = new dog[1];
	SecondMasterDogs[0].SetDogsMerit("Elsa", 5, 2);
	SecondMaster.SetMastersMerit("Irina", SecondMasterDogs);
	SecondMaster.GetMastersMerit();
	cout << "Irina`s dogs:\n\n";
	SecondMasterDogs[0].GetDogsMerit();
	cout << "------------------------------------\n";
	cout << "\n\n";

	cout << "All club has: " << FirstMaster.GetMastersCount() <<" members" << endl;
	cout << "All club has: " << FirstMasterDogs[0].GetDogsCount() << " dogs" << endl;*/
	int master_count, dog_count, d_weight , d_age, i = 0;
	string m_name , d_name ;
	master* one = new master[0];
	int a = 0;
	vector<master> masters;
	vector<dog> doges;
	vector<int> count;
	vector<string> m_names;
	do {
		cout << "\n\nAdd the new master? - 1\nAdd the new dog? - 2\nPrint all masters? - 3\nExit? - esc\n\n";
		cin >> a;
		switch (a) {
			
			
		case 1:

			cout << "How many masters create?\n\n";
			cin >> master_count;
			one = new master[master_count];
			if (cin.fail()) {
				cout << "Eror, try one more time\n";
				cin.clear();
				cin.ignore(32767, '\n');
				system("pause");
				system("cls");
				continue;
			}
			for (int i = 0; i < master_count; i++) {

				cout << "Insert master name: ";

				cin >> m_name;
				m_names.push_back(m_name);
				cout << "How many dogs master have?\n";
				cin >> dog_count;
				if (cin.fail()) {
					cout << "Eror, try one more time\n";
					cin.clear();
					cin.ignore(32767, '\n');
					system("pause");
					system("cls");
					continue;
				}
				count.push_back(dog_count);
				dog* dogs = new dog[dog_count];
				
				for (int j = 0; j < dog_count; j++) {

					cout << "Insert dog`s name, weight, age: \n";
					cin >> d_name >> d_weight >> d_age;
					dogs[j].SetDogsMerit(d_name, d_weight, d_age);
					doges.push_back(dogs[j]);
				}
				
				one[i].SetMastersMerit(m_name, dogs);
				masters.push_back(one[i]);
			}
			break;
		
		case 3:
			
			for (int i = 0; i < masters.size(); i++) {
				cout << "\n";
				masters[i].GetMastersMerit();
				cout << "Master`s " << i + 1 << " dogs\n";
				masters[i].GetMastersDogsMerit(count[i]);
			}
			
			
			cout << "All club has: " << masters[0].GetMastersCount() << " members" << endl;
			cout << "All club has: " << doges[0].GetDogsCount() << " dogs" << endl;
			break;
			cout << "Press any key to continue . . .\n";
			puts("Press 'esc' to exit . . .");

		case 2:
			for (int i = 0; i < masters.size(); i++) {
				masters[i].GetMastersMerit();
			}
			cout << "Which master to add new dog? > \n\n";
			cin >> i;
			i -=1;
			if (cin.fail()) {
				cout << "Eror, try one more time\n";
				cin.clear();
				cin.ignore(32767, '\n');
				system("pause");
				system("cls");
				continue;
			}
			
			cout << "How many dogs create\n";
			cin >> dog_count;
			if (cin.fail()) {
				cout << "Eror, try one more time\n";
				cin.clear();
				cin.ignore(32767, '\n');
				system("pause");
				system("cls");
				continue;
			}

			dog* dogs = new dog[count[i] + dog_count];
			static int j = 0;
			for (int j = 0; j < (count[i]); j++) {
				dogs[j] = masters[i].GetDogs(count[i], j);
				
			}
			for (int j = 0; j < dog_count; j++) {
				cout << "Insert dog`s name, weight, age: \n";
				cin >> d_name >> d_weight >> d_age;
				dogs[count[i]+j].SetDogsMerit(d_name, d_weight, d_age);
			}
			count[i] = (count[i] + dog_count);
			masters[i].SetMastersMerit(m_names[i], dogs);
			break;
		}
		cin.clear();
		cin.ignore(32767, '\n');
	} while (_getch() != 27);
	
}