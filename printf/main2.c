#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

void	ft_printhex(int n) {
    int c;

    if (n >= 16)
        ft_printhex(n / 16);
    c = n % 16 + (n % 16 < 10 ? '0' : 'a' - 10);
    ft_putchar(c);
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

void    print_pointer(const void *addr)
{
    unsigned char *p = (unsigned char *)addr;
    size_t i = 9;
    write(1, "0x", 3);
    while(i > 3)
    {
  //      if (p[i] < 10)
 //           ft_putnbr(p[i]);
        ft_printhex(p[i]);

        i--;
    }
}
int     main()
{
    int a = 68;

    void *k = &a;

    printf("number = %+-013d, pointer = %p\n", a, &a);
    print_pointer(k);
}