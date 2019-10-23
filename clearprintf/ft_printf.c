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

        end = i;
        while ((!(is_diouxX(walk[end]))) && (!(is_csp(walk[end]))) && walk[end] != 'f')
            end++;

        if (walk[end] == 'd' || walk[end] == 'i')
            format_print_di((va_arg(ap, int)), walk, i, end);
/*        else if (*walk == 'c')
            format_print_char((char)(va_arg(ap, unsigned char)), walk, i, end);
        else if (*walk == 's')
            format_print_str((va_arg(ap, char *)), walk, i, end);
        else if (*walk == 'p')
            print_pointer(va_arg(ap, const void *));
        else if (*walk == 'o' || *walk == 'x' || *walk == 'X')
            format_print_ouxX(va_arg(ap, unsigned int), walk, i, end);
*/
        i = end;
        i++;
    }
    va_end(ap);
}
