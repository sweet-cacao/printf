#include "ft_printf.h"

int     count_length(int n)
{
    int res;

    res = 0;
    while (n > 0)
    {
        n = n / 10;
        res++;
    }
}