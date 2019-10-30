#include "ft_printf.h"

void	ft_printf(char *format, ...)
{
    va_list ap;
    char *walk;
    int i;
    int end;

    i = 0;
    walk = format;
    va_start(ap, walk);
    while (walk[i] != '\0')
    {
        while (walk[i] != '%' && walk[i] != '\0')
        {
            ft_putchar(walk[i]);
            i++;
        }
        i++;
        //here must be checked if the string has the right order or not and what to do, parse, or print arguments
        end = i;
        while ((!(is_diouxX(walk[end]))) && (!(is_csp(walk[end]))) && walk[end] != 'f')
            end++;
        ft_parse(ap, walk, i, end);
        i = end;
        i++;
    }
    va_end(ap);
}
