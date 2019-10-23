#include "ft_printf.h"

void	ft_printhex(int n) {
    int c;

    if (n >= 16)
        ft_printhex(n / 16);
    c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
    write(1, &c, 1);
}

void    print_pointer(const void *addr)
{
    unsigned char *p = (unsigned char *)addr;
    size_t i = 9;
    write(1, "0x", 3);
    while(i > 3)
    {
        ft_printhex(p[i]);
        i--;
    }
}
