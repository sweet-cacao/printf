#include "ft_printf.h"
//приоритет точки над нулем, если есть точка то пробелами заполняется ширина. флаги могут стоять ТОЛЬКО до цифр
//пробел до он помещает в пределах минимальной ширины поля если нет знака у самого числа
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
    if (is_number(str[i]))
    {
        width = atoi(&str[i]);
        while(is_number(str[i]))
            i++;
    }
    if (str[i] == '.') //только для float
    {
        i++;
        precision = atoi(&str[i]);
    }

        if (str[i] == '-' && earlier_check(str[i], start, i))
        {
            min = 1;
            if (arg < 0)
                ft_putchar('-');
        }
        if (str[i] == '0' && earlier_check(str[i], start, i)){

        }
        i++;
    }
}
