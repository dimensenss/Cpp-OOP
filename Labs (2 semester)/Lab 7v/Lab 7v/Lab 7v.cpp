#include "foo.h"

int main()
{
	srand(time(NULL));
	int x = 0;
	char fname[] = "text.bin";

	input(fname);
	cout << "First bin file output:\n";
	read(fname);
	x = sum(fname);
	cout << "\n\n\n";
	cout << "Sum = " << x;
	cout << "\n\n\n";	
	sort(fname);
	cout << "\n";
	cout << "Second bin file output:\n";
	read(fname);
	cout << "\n\n\n";
	system("pause");
	
}