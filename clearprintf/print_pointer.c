#include "ft_printf.h"

void	ft_printhex(int n) {
    int c;

    c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
    write(1, &c, 1);
}

void    print_pointer(const void *addr)
{
    unsigned char *p = (unsigned char *)&addr;
    int i = 8;
    int col = 0;
    write(1, "0x", 2);

    i--;
    while (i >= 0 && p[i] == 0)
    	i--;
	if (i >= 0 && (p[i] / 16) == 0)
	{
		ft_printhex(p[i]);
		i--;
	}
    while(i >= 0)
	{
    	ft_printhex(p[i] / 16);
    	ft_printhex(p[i]);
    	i--;
	}
}
/*
int main() {
	void *str = "lay";
	int i = 8;
	int b = 7;
	int *k = (int *)0x000d721a01;
	print_pointer(k);

	printf("\np = %p\n", k);
	unsigned long long a = (unsigned long long)&b;
//	printf("\np = %llu\n", (unsigned long long)&b);
//	printf("\np = %llu\n", a);
//
//	int x = 8;
//	while (x-- > 0)
//	{
//		printf("%x ", (int)(a << (x * 8) & 0xF));
//	}


//	unsigned long long p = (unsigned long long)&b;
//	printf("%p\n", &b);
//
//	unsigned char *a = (unsigned char *)&p;
//	int c = 0;
//	while (c < 8)
//		printf("%x\n", a[c++]);


	//ft_putstr(&k);
}
*/