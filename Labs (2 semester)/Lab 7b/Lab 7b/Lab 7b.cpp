#include "foo.h"
#define N 10

int main()
{
	srand(time(NULL));

	char fname1[] = "text1.txt";

	int arr1[N];
	int arr2[N];
	int x = 0;
	
	fill_array(arr1, N);
	cout << "Fisrt array\n";
	print_array(arr1, N);
	foo(fname1, arr1, N);
	sum_foo(fname1, arr2, &x, N);
	
	cout << "\n\nSecond array\n";
	print_array(arr2,N);
	
	cout << "\n\nSum: " << x << endl;
	system("pause");
}

