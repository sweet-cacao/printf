#include "ft_printf.h"

int    format_print_p(void *arg, char *str, int start, int end)
{
    t_list a;
    int i = start;
    int len_arg;

    a = zero_struct();
    a.precision = 14;
    a = fill_struct(a, &i, str);
    if (str[i] == 'p')
    {
        if (a.zero == 1 && a.isp == 1)
            a.zero = 0;
        if (a.min == 1)
        {
            write(1, "0x", 2);
            if (a.precision > 14)
            {
                i = 14;
                while (i < a.precision)
                {
                    ft_putchar('0');
                    i++;
                }
            }
            print_pointer(arg);
            if (a.width > 14)
            {
                i = a.precision;
                while (i < a.width)
                {
                    ft_putchar(' ');
                    i++;
                }
            }
        }
        else
        {
                if (a.zero == 1)
                {
                    write(1, "0x", 2);
                    i = 14;
                    if (a.width > 14) {
                        while (i < a.width) {
                            ft_putchar('0');
                            i++;
                        }
                    }
                }
                else
                {
                    i = a.precision;
                    if (a.width > a.precision)
                    {
                        while (i < a.width)
                        {
                            ft_putchar(' ');
                            i++;
                        }
                    }
                    write(1, "0x", 2);
                    if (a.precision > 14)
                    {
                        i = 14;
                        while (i < a.precision)
                        {
                            ft_putchar('0');
                            i++;
                        }
                    }
                }
            print_pointer(arg);
        }
        return (1);
    }
    return (0);
}

