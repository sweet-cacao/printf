#include "ft_printf.h"

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_putstr(char *s)
{
    while (*s)
        ft_putchar(*s++);
}

void	ft_putnbr(int n)
{
    if (n == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    if (n < 0)
    {
        n *= -1;
        write(1, "-", 1);
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    ft_putchar(n % 10 + 48);
}

size_t		ft_strlen(const char *str)
{
    size_t sum;

    sum = 0;
    while (*str != '\0')
    {
        sum++;
        str++;
    }
    return (sum);
}