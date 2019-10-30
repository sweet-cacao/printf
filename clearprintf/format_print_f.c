#include "ft_printf.h"

void    print_second(long long int a)
{
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
}

void    print_float(double f, int precision)
{
	signed long int first;
	signed long int second;

	if (f < 0)
	{
		ft_putchar('-');
		f = f * (-1);
	}
}

void    format_print_f(double f, char *str, int start, int end)
{
    double_print(f);
}
