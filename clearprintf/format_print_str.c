#include "ft_printf.h"

void    ft_putstr_p(char *str, int precision) //putstr with precision
{
    int i;

    i = 0;
    while (i < precision)
    {
        ft_putchar(str[i]);
        i++;
    }
}

int    format_print_s(char *arg, char *str, int start, int end)
{
    t_list a;
    int i = start;
    int len_arg;

    a = zero_struct();
    a = fill_struct(a, &i, str);
    if (str[i] == 's')
    {
        if (a.isp == 1)
            len_arg = a.precision;
        else
            len_arg = ft_strlen(arg);
        if (a.min == 1)
        {
            ft_putstr_p(arg, len_arg);
            if (a.width > len_arg)
            {
                while (a.width > len_arg)
                {
                    ft_putchar(' ');
                    a.width--;
                }
            }
        }
        else
        {
            if (a.width > len_arg)
                format_width_c(a, len_arg);
            ft_putstr_p(arg, len_arg);
        }
        return (1);
    }
    return (0);
}