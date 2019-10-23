#include "ft_printf.h"

int main() {
    ft_printf("Hello, World%0+10d, %0-10d, %10d!\n", 5, 6, 7);
    return 0;
}