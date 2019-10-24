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

int main()
{
	float a = 945678935245678987654.987;
	format_print_f(a, 10);
	printf("\nf = %.10f\n,", a);
	return (0);
}