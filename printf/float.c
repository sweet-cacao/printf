#include <stdio.h>

int main()
{
	long int a = 128;
	long int b = 128;
	float c = 0.128;
	int cel;
	int ost;
	int el;
	float res = a * b * c;
	
	long int r = 128 * 128 * 128;

	printf("%#+0010lld", r);
}
