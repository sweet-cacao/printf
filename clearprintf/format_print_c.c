#include "ft_printf.h"

//space and + dont influence str, c,p but zero, minus do
//with pointers zeroes are placed after 0x, but spaces before 0x
//for p if dot is after minus it places zeroes after 0x
//precision works with strings
//precision works with pointers in a very strange way, ot doesnt make the pointer fewer, but implements zeroes before 0x if precision is bigger than than the length of pointer

void    format_width_c(t_list a)
{
    while (a.width > 1)
    {
        if (a.zero == 1)
            ft_putchar('0');
        else
            ft_putchar(' ');
        a.width--;
    }
}

int    format_print_c(char arg, char *str, int start, int end)
{
    t_list a;
    int i = start;

    a = zero_struct();
    a = fill_struct(a, &i, str);
    if (str[i] == 'c')
    {
        if (a.min == 1)
        {
            ft_putchar(arg);
            while (a.width > 1)
            {
                ft_putchar(' ');
                a.width--;
            }
        }
        else
        {
            format_width_c(a);
            ft_putchar(arg);
        }
        return (1);
    }
    return (0);
}



