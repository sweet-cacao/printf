#include "ft_printf.h"

void format_print_f(float f, int precision)
{
	signed long int first;
	signed long int second;

	if (f < 0)
	{
		ft_putchar('-');
		f = f * (-1);
	}
	first = (signed long int)f;
	int len_arg = count_length(first);

	ft_putnbr(first);
	ft_putchar('.');
	f -= (float)first;
/*
	while (precision > 9)
	{
		f = f * 1000000000;
		first = (signed long int)f;
		len_arg = count_length(first);
		ft_putnbr(first);
		f -= first;
		precision -= 9 ;
	}
	*/
	while (precision > 0)
	{
		f = f * 10;
		first = (signed long int)f;
		ft_putnbr(first);
		f -= first;
		precision -= 1;
	}

}

typedef union s_double t_double;

typedef struct          s_tlist
{
    long long int mantissa : 52;
    long long int exponent : 11;
    long long int sign : 1;
}                       t_tlist;

union s_double
{
    double a;
    t_tlist k;
};

void    print_second(long long int a) {
    if (a == 0)
        ft_putnbr(0);
    while (a > 0)
    {
        ft_putnbr(a % 2);
        a = a / 2;
    }
    ft_putchar('\n');
}

float step(int a, int b)
{
    float n;
    n = 1;
    int min = 0;
    if (b < 0)
    {
        b *= -1;
        min = 1;
    }
    while (b > 0)
    {
        n = n * a;
        b--;
    }
    if (min == 1)
    {
        n = 1 / n;
    }
    return (n);
}

void double_print(double d)
{
    t_double aDouble;

    aDouble.a = d;
    int poryadok = aDouble.k.exponent - 1023;
    double chislo = (aDouble.k.mantissa / (step(2, 52))) + 1;
    printf("f = %.10f\n", chislo);
 //   print_second(chislo);
    print_second(aDouble.k.mantissa);
    print_second(aDouble.k.exponent);
    print_second(aDouble.k.sign);
    printf("man %lld, exp %d, sign %d", aDouble.k.mantissa, aDouble.k.exponent, aDouble.k.sign);
}

int main()
{
	float a = 1.3267890678;
	double_print(a);
//	format_print_f(a, 10);
	printf("\nd = %.10f\n,", a);
	return (0);
}
