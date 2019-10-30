#include "ft_printf.h"
//приоритет точки над нулем, если есть точка то пробелами заполняется ширина. флаги могут стоять ТОЛЬКО до цифр
//пробел до он помещает в пределах минимальной ширины поля если нет знака у самого числа
//нужно еще дописать пробел до числа
//дописать, что делать с нулём

t_list  fill_struct(t_list a, int *i, char *str)
{
    while (first_flag(str[*i]))
    {
        if (str[*i] == '-')
            a.min = 1;
        if (str[*i] == '#')
            a.hash = 1;
        if (str[*i] == '+')
            a.plus = 1;
        if (str[*i] == '0')
            a.zero = 1;
        if (str[*i] == ' ')
            a.space = 1;
        (*i)++;
    }
    if (a.min == 1)
        a.zero = 0;
    if (a.plus == 1 || a.min == 1)
        a.space = 0;
    if (is_number(str[*i]))
    {
        a.width = atoi(&str[*i]);
        while(is_number(str[*i]) || str[*i] == '0')
            (*i)++;
    }
    if (str[*i] == '.') //только для float
    {
        (*i)++;
        a.precision = atoi(&str[*i]);
        a.isp = 1;
        while(is_number(str[*i]) || str[*i] == '0')
            (*i)++;
    }
    return (a);
}

t_list	zero_struct()
{
	t_list a;
	a.hash = 0;
	a.min = 0;
	a.plus = 0;
	a.precision = 0;
	a.space = 0;
	a.width = 0;
	a.isp = 0;
	return (a);
}
void    format_width(t_list a, int len_arg)
{
    int i;

    i = 0;
    if (a.width > len_arg)
    {
        i = 0;
        while (i < (a.width - len_arg))
        {
            if (a.zero == 1)
                ft_putchar('0');
            else
                ft_putchar(' ');
            i++;
        }
    }
}

void    format_choose_sign(int arg, int *len_arg, t_list a)
{
    if (arg < 0)
    {
        ft_putchar('-');
        (*len_arg)++;
    }
    if (arg > 0 && a.plus == 1)
    {
        ft_putchar('+');
        (*len_arg)++;
    }
}

int    format_print_di(int arg, char *str, int start, int end)
{
	t_list a;
    int i = start;
    int len_arg;

    a = zero_struct();
    a = fill_struct(a, &i, str);
    if (is_diouxX(str[i]))
    {
        len_arg = count_length(arg);
        if (a.min == 1)
        {
            format_choose_sign(arg, &len_arg, a);
            ft_putnbr(arg);
            format_width(a, len_arg);
        }
        else
        {
            i = 0;
            if (a.plus == 1)
                len_arg++;
            format_width(a, len_arg);
            format_choose_sign(arg, &len_arg, a);
            ft_putnbr(arg);
        }
        return (1);
    }
    return (0);
}
