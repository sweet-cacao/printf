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


int first_flag(char c)
{
    return c == '#' || c == '0' || c == '-' || c == '+' || c == ' ';
}

int is_diouxX(char c)
{
    return c == 'd' || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X';
}

int is_csp(char c) {
    return c == 'c' || c == 's' || c == 'p';
}

int is_number(char c)
{
    return c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9';
}

int is_modifier(char c)
{
    if (c == 'l' || c == 'h')
        return (1);
    return (0);
}

int     count_length(int n)
{
    int res;

    res = 0;
    if (n == 0)
        return (1);
    while (n != 0)
    {
        n = n / 10;
        res++;
    }
    return(res);
}

void    ft_bzero(void *s, size_t n)
{
    char *p;

    p = (char *)s;
    while (n-- > 0)
    {
        *(p++) = 0;
    }
}

char    *ft_strcpy(char *dst, const char *src)
{
    size_t i;

    i = 0;
    while (src[i])
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (dst);
}

char    *ft_strnew(size_t size)
{
    char *p;

    p = malloc(size + 1);
    if (p)
    {
        ft_bzero(p, (size + 1));
        return (p);
    }
    return (NULL);
}

t_list	zero_struct()
{
    t_list a;
    a.hash = 0;
    a.min = 0;
    a.plus = 0;
    a.precision = 0;
    a.space = 0;
    a.width = 0;
    a.zero = 0;
    return (a);
}

int             ft_strcmp(const char *s1, const char *s2)
{
    unsigned char   *p1;
    unsigned char   *p2;
    size_t                  i;

    i = 0;
    p1 = (unsigned char *)s1;
    p2 = (unsigned char *)s2;
    while (p1[i] && p2[i] && p1[i] == p2[i])
        i++;
    return (p1[i] - p2[i]);
}
