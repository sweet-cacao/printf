#include "ft_printf.h"

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
