#include <stdio.h>
#include <stdarg.h>
#define MAXARGS 31
#include <stdlib.h>
#include <unistd.h>
#define MAXEL 10
#define MAXSTR 1000
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

void	f1(int n_ptrs, ...)
{
	va_list ap;
	char *array[MAXARGS];
	int ptr_no = 0;

	if (n_ptrs > MAXARGS)
		n_ptrs = MAXARGS;
	va_start(ap, n_ptrs);
	while (ptr_no < n_ptrs)
	{
		array[ptr_no++] = va_arg(ap, char *);
	}
	va_end(ap);
	ptr_no = 0;
	while (ptr_no < n_ptrs)
	{
		printf("%s", array[ptr_no]);
		ptr_no++;
	}
}

int first_flag(char c)
{
	return c == '#' || c == '0' || c == '-' || c == '+' || c == ' ';
}

void format_func(int start, int end, char *format)
{
	char array[MAXEL][MAXSTR];
	int i = start;
	int j = 0;
	char str[MAXSTR];
	while (i  < end)
	{
		if (first_flag(format[i]) && earlier_check(format[i], array) && (!(is_in_array(format[i], array))))
		{

			array[j][0] = format[i];
		}
		if (is_number(format[i]) && format[i] != '0' && earlier_check_for_first(i, format[i]))
		{
			int k = 0;
			while(is_number(format[i]))
			{
				str[k] = format[i];
				i++;
				k++;
			}
			strcpy(array[j],str);
		}
		if (format[i] == '.' && (!(earlier_check(format[i], array))))
		{
			int k = 0;
			bzero(str, MAXSTR);
			i++;
			str[k] = '.';
			while(is_number(format[i]))
			{
				str[k] = format[i];
				i++;
				k++;
			}
			strcpy(array[j],str);
		}
		if (is_diouxX(format[start]) && is_flag_size(format[i]) && (!(earlier_check(format[i], array)))) //достаточно проверить первую h l
		{
			while((!(is_diouxX(format[i]))))
			{
				int k = 0;
				array[j][k] = format[i];
			}
		}


	}

}
void	print_number(char *format, ...)
{
	va_list ap;
	char *walk;
	int i;
	char symbols[10];
	i = 0;
	walk = format;
	va_start(ap, walk);
	while (walk[i] != '\0')
	{
		while (walk[i] != '%' && walk[i] != '\0')
		{
			ft_putchar(walk[i]);
			i++;
		}
		i++;
		int start = i;
		int end = i;
		while (walk[end] != 'd' && walk[end] != 's' && walk[end] != 'c' && walk[end] != 'x' && walk[end] != 'X' && walk[end] != 'f')
			end++;
		format_func(start, end, walk);
//		check_array() проверить все ли символы могут выполняться вместе и правильность порядка
//		putnbr_format(va_arg(ap, end, array);
//		если минус , то ноль не выполняется
		if (*walk == 'd')
			ft_putnbr((va_arg(ap, int)));
		else
			ft_putchar((va_arg(ap, char)));
		walk++;
	}
	va_end(ap);
}
int main()
{

//	f1(3, "hey", "gay", "play");
	print_number("number = %d, and %d", 5, 6);
}