#include "ft_printf.h"

typedef union   u_test
{
    unsigned long long  l;
    struct
    {
        unsigned long long ma: 52;
        unsigned long long rate : 11;
        unsigned long long sign : 1;
    }                   s;
    double              d;
}               t_test;

int main() {
    int a = 8;
    t_test aa;

    aa.l = 0x3FEC600000000000;
    ft_printf("Hello, World%0+10d, %0-10d, %10d, %0-10c!\n", 5, 6, 7, 'a');



    int d = (aa.s.rate - 1023);

    printf("d = %d\n", d);
    printf("c = %lf\n", aa.d);
    return 0;
}
//space and + dont influence str, c,p but zero, minus do
//with pointers zeroes are placed after 0x, but spaces before 0x
//for p if dot is after minus it places zeroes after 0x
//precision works with strings
//precision works with pointers in a very strange way, ot doesnt make the pointer fewer, but implements zeroes before 0x if precision is bigger than than the length of pointer
//prints strange symbols after first flags
