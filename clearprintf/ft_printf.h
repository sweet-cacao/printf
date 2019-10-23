#ifndef CLEARPRINTF_FT_PRINTF_H
#define CLEARPRINTF_FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

void    print_pointer(const void *addr);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_printf(char *format, ...);
void	ft_putstr(char *s);
int     is_csp(char c);
int     is_diouxX(char c);
int     first_flag(char c);
int     is_number(char c);

#endif
