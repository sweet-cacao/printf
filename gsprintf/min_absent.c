#include "ft_printf.h"

void    min_absent(int arg, int len_arg, t_list a)
{
    size_t i;

    i = 0;
    if (a.width > len_arg)
    {
        if (a.precision > len_arg)
            len_arg = a.precision;
        if (a.plus == 1 || arg < 0)
            len_arg++;
        if (a.zero == 1)
        {
            if (arg < 0)
            {
                ft_putchar('-');
                arg = -arg;
            }
            else if (arg > 0 && a.plus == 1)
                ft_putchar('+');
        }
        int count = count_length(arg);

        while (i < (a.width - len_arg))
        {
            if (a.zero == 1)
                ft_putchar('0');
            else
                ft_putchar(' ');
            i++;
        }
        if (arg > 0 && a.plus == 1 && a.zero == 0)
            ft_putchar('+');
        while (a.precision - count > 0)
        {
            ft_putchar('0');
            count++;
        }
    }
    else if (a.width < len_arg)
    {
        if (a.space == 1 && arg > 0)
            ft_putchar(' ');
        if (arg > 0 && a.plus == 1)
            ft_putchar('+');
    }
    ft_putnbr(arg);
}
