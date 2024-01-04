
#include <iostream>

int main()
{
	
		int x = 1; // x = 1
		int y = 2; // y = 2
		int temp = 0;
		temp = x;
		x = y; // x = 2
		y = temp; // y =1



		x = x + y;
		y = x - y; // y = 2 
		x -= y; // x = 1
}