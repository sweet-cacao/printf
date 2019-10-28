#include "ft_printf.h"

int    format_print_s(char *arg, char *str, int start, int end)
{
    t_list a;
    int i = start;
    int len_arg;

    a = zero_struct();
    a = fill_struct(a, &i, str);
    if (str[i] == 's')
    {
        len_arg = ft_strlen(arg);
        if (a.min == 1)
        {

            ft_putstr(arg);
            while (a.width < len_arg)
            {
                ft_putchar(' ');
                a.width--;
            }
        }
        else
        {
            format_width_c(a);
            ft_putstr(arg);
        }
    }
}