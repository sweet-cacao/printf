#include "ft_printf.h"
//приоритет точки над нулем, если есть точка то пробелами заполняется ширина. флаги могут стоять ТОЛЬКО до цифр
//пробел до он помещает в пределах минимальной ширины поля если нет знака у самого числа
//нужно еще дописать пробел до числа
//дописать, что делать с нулём
void    format_print_di(int arg, char *str, int start, int end)
{
    int zero = 0;
    int hash = 0;
    int min = 0;
    int plus = 0;
    int space;
    int i = start;
    int width = 0;
    int precision = 0;
    int number_length;
    while (first_flag(str[i]))
    {
        if (str[i] == '-')
            min = 1;
        if (str[i] == '#')
            hash = 1;
        if (str[i] == '+')
            plus = 1;
        if (str[i] == '0')
            zero = 1;
        if (str[i] == ' ')
            space = 1;
        i++;
    }
    if (min == 1)
        zero = 0;
    if (plus == 1 || min == 1)
        space = 0;

    if (is_number(str[i]))
    {
        width = atoi(&str[i]);
        while(is_number(str[i]) || str[i] == '0')
            i++;
    }
    if (str[i] == '.') //только для float
    {
        i++;
        precision = atoi(&str[i]);
        while(is_number(str[i]) || str[i] == '0')
            i++;
    }
    int len_arg;
    if (is_diouxX(str[i]))
    {
        len_arg = count_length(arg);
        if (min == 1)
        {
            if (arg < 0)
            {
                ft_putchar('-');
                len_arg++;
            }
            if (arg > 0 && plus == 1)
            {
                ft_putchar('+');
                len_arg++;
            }
            ft_putnbr(arg);
            if (width > len_arg)
            {
                i = 0;
                while (i < (width - len_arg))
                {
                    if (zero == 1)
                        ft_putchar('0');
                    else
                        ft_putchar(' ');
                    i++;
                }
            }
        }
        else
        {
            len_arg++;
            i = 0;
            if (width > len_arg)
            {
                if (plus == 1)
                    len_arg++;
                while (i < (width - len_arg))
                {
                    if (zero == 1)
                        ft_putchar('0');
                    else
                        ft_putchar(' ');
                    i++;
                }
            }
            if (arg < 0)
                ft_putchar('-');
            if (arg > 0 && plus == 1)
                ft_putchar('+');
            ft_putnbr(arg);
        }
    }
}
