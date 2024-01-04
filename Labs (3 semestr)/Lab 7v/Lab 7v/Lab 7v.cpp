#include <iostream>
#include <fstream>
using namespace std;
//void foo(int* mas, bool f) {
//	if (f) {
//		int i = 0;
//		while (i != 10) {
//			if (i == 4)
//				break;
//			else
//				mas[i] = 77;
//			++i;
//		}
//	}
//	else {
//		int i = 0;
//		while (i != 10) {
//			if (i > 4) {
//				mas[i] = 88;
//				++i;
//			}
//			else {
//				++i;
//				continue;
//			}
//		}
//	}
//}
int main() {
	int mas[] = { 1,2,3,4,11,6,7,8,9,10 };
	int x = 0;
	int m = 88, k = 77;

	fstream f1;

	f1.exceptions(fstream::badbit | fstream::failbit);
	try {
		f1.open("text.bin", ios::binary | ios::out);
		f1.write((char*)mas, sizeof(mas));
		f1.close();


		f1.open("text.bin", ios::binary | ios::in | ios::out);
		f1.seekg(4*sizeof(int));
		f1.read((char*)&x, sizeof(int));
		if (x % 2 == 0) {
			for (int i = 5; i < 10; i++) {
				f1.seekp(i * sizeof(int));
				f1.write((char* )&m,sizeof(int));
			}
		}
		else if (x % 2 != 0) {
			for (int i = 0; i < 4; i++) {
				f1.seekp(i * sizeof(int));
				f1.write((char*)&k, sizeof(int));
			}
		}
		f1.close();
		
		f1.open("text.bin", ios::binary | ios::in);
		for (int i = 0; i < 10; i++) {
			f1.read((char*)&mas[i], sizeof(int));
			cout << mas[i] << " ";
		}
		f1.close();
	}
	catch (const exception& ex) {
		cout << ex.what() << "\n";
	}
}
