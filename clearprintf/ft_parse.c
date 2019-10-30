#include "ft_printf.h"

void    ft_parse(va_list ap, char *walk, int i, int end) {
    if (walk[end] == 'd' || walk[end] == 'i')
        format_print_di((va_arg(ap, int)), walk, i, end);
    if (walk[end] == 'c')
        format_print_c((char) (va_arg(ap, unsigned char)), walk, i, end);
    if (walk[end] == 's')
        format_print_s((va_arg(ap, char *)), walk, i, end);
    if (walk[end] == 'p')
        format_print_p(va_arg(ap, void *), walk, i, end);
/*
        if (walk[end] == 'f')
            format_print_f((va_arg(ap, double)), walk, i, end);
        if (walk[end] == 'o' || walk[end] == 'x' || walk[end] == 'X')
            format_print_ouxX(va_arg(ap, unsigned int), walk, i, end);
}
*/
}