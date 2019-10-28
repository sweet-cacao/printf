#include "ft_printf.h"
//приоритет точки над нулем, если есть точка то пробелами заполняется ширина. флаги могут стоять ТОЛЬКО до цифр

#define SETMIN(chr, a) if (chr == '-') a.min = 1
#define SETHASH(chr, a) if (chr == '#') a.hash = 1
#define SETPLUS(chr, a) if (chr == '+') a.plus = 1
#define SETZERO(chr, a) if (chr == '0') a.zero = 1
#define SETSPACE(chr, a) if (chr == ' ') a.space = 1

t_list    flag_ignore(t_list a)
{
    if (a.min == 1)
        a.zero = 0;
    if (a.plus == 1 || a.min == 1)
        a.space = 0;
    if (a.precision > 0 || a.width > a.precision)
        a.zero = 0;
    return (a);
}

//t_list set_structure(t_list a, char *str, int *i)
//{
//    while (first_flag(str[*i]))
//    {
//        SETMIN(str[*i], a);
//        SETHASH(str[*i], a);
//        SETPLUS(str[*i], a);
//        SETZERO(str[*i], a);
//        SETSPACE(str[*i], a);
//        *i++;
//    }
//
//    if (is_number(str[*i]))
//    {
//        a.width = atoi(&str[*i]);
//        while(is_number(str[*i]) || str[*i] == '0')
//            *i++;
//    }
//    if (str[*i] == '.') //только для float
//    {
//        *i++;
//        a.precision = atoi(&str[*i]);
//        while(is_number(str[*i]) || str[*i] == '0')
//            *i++;
//    }
//    return (a);
//}

void    format_print_di(int arg, char *str, int start, int end)
{
    t_list a = zero_struct();
    int i = start;
    int number_length;
    while (first_flag(str[i]))
    {
        SETMIN(str[i], a);
        SETHASH(str[i], a);
        SETPLUS(str[i], a);
        SETZERO(str[i], a);
        SETSPACE(str[i], a);
        i++;
    }

    if (is_number(str[i]))              // ширина
    {
        a.width = atoi(&str[i]);
        while(is_number(str[i]) || str[i] == '0')
            i++;
    }
    if (str[i] == '.')                      // точность
    {
        i++;
        a.precision = atoi(&str[i]);
        while(is_number(str[i]) || str[i] == '0')
            i++;
    }

    char *tmp = NULL;
    char *dst = NULL;
    while (is_modifier(str[i]))
    {
        if (tmp)
        {
            dst = ft_strnew(2);
            ft_strcpy(dst, tmp);
            dst[1] = str[i];
            free(tmp);
            tmp = dst;
            free(dst);
        }
        if (!tmp)
        {
            tmp = ft_strnew(1);
            tmp[0] = str[i];
        }

        a.modifier = tmp;
        i++;
    }
 //   printf("modifier is %s", a.modifier); // seg fault ????????????????
        if (ft_strcmp(a.modifier, "hh"))
        {
            arg = (signed char)arg;
            printf("1\n");
        }


//    a = set_structure(a, str, &i);
    a = flag_ignore(a);
    int len_arg;
    if (is_diouxX(str[i]))
    {
        len_arg = count_length(arg);
        if (a.min == 1)
        {
            min_present(arg, len_arg, a);
        }
        else if (a.min == 0)
        {
            min_absent(arg, len_arg, a);
        }
    }
}
