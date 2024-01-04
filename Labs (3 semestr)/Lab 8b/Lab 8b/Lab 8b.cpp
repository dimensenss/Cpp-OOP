
#include "Header.h"

int main()
{
	srand(time(0));
	int a = 0, b = 0, n = 0, f = 0;
	Array<int> ob;
	while (1) {
		cout << "1 - Enter ind\n2 - Fill array to ind\n3 - Print array\n4 - Calc. average\n5 - Calc. sum\n6 - Calc. max\n";
		cin >> a;
		try {
			switch (a) {

			case 1:
				system("cls");
				cout << "Enter ind, size > ";
				cin >> b >> n;
				ob(b, n);
				system("pause");
				system("cls");
				break;
			case 2:
				system("cls");
				if (ob.get_ind() <= 0)
					throw exception("ind <= 0");

				for (int i = 0; i < ob.get_ind(); i++) {
					ob.fill_arr(rand() % 10, i);
				}
				system("pause");
				system("cls");
				break;
			case 3:
				
				system("cls");

				if (ob.get_ind() <= 0)
					throw exception("ind <= 0");

				ob.print();
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");

				if (ob.get_ind() <= 0)
					throw exception("ind <= 0");

				ob.average_arr();
				system("pause");
				system("cls");
				break;
			case 5:
				system("cls");

				if (ob.get_ind() <= 0)
					throw exception("ind <= 0");

				ob.sum_arr();

				system("pause");
				system("cls");
				break;
			case 6:
				system("cls");
				cout << "Enter ind for finding max >";
				cin >> f;
				if (ob.get_ind() <= 0)
					throw exception("ind <= 0");
				if (ob.get_ind() < f || f < 0)
					throw exception("Eror input ind");

				ob.print();
				cout << "\n" << "Max: " << ob[f] << "\n";
				
				system("pause");
				system("cls");
				break;
			}
		}
		catch (const exception ex) {
			cout << ex.what() << "\n";
		}
	}
}