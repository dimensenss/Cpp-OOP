#include "foo.h"
void foo(char* S, char* S1, int num, int amount)
{
	int p_1 = 0;
	while (p_1 != num - 1 && *S != '\0')
	{
		if (*S == ' ') p_1++;
		S++;
	}
	int p_2 = 0;
	while (p_2 != amount && *S != '\0')
	{
		if (*S == ' ') p_2++;
		*S1 = *S;
		S1++; S++;
	}
	*S1 = '\0';
}
void counter(char* S, int* count)
{
	int word;
	int i = 0;
	while (*(S + i) == ' ' && *(S + i) != '\0')
		i++;
	word = 0;
	while (*(S + i) != '\0') {
		if (*(S + i) != ' ' && word == 0)
		{
			word = 1;
			*count = *count+1;
		}
		else if (*(S + i) == ' ')
			word = 0;
		i++;
	}
}