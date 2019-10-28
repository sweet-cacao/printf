#include "ft_printf.h"

void    min_present(int arg, int len_arg, t_list a)
{
    size_t i;

    i = 0;
    if (arg < 0)
        len_arg++;
    if (arg > 0 && a.plus == 1)
    {
        ft_putchar('+');
        len_arg++;
    }
    if (a.width > len_arg && a.space == 1)
    {
        ft_putchar(' ');
        len_arg++;
    }
    int count = count_length(arg);
    while (a.precision - count > 0)
    {
        ft_putchar('0');
        count++;
        len_arg++;
    }
    ft_putnbr(arg);
    if (a.width > len_arg)
    {
        i = 0;
        while (i < (a.width - len_arg))
        {
            ft_putchar(' ');
            i++;
        }
    }
}

