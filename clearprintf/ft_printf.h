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
size_t	ft_strlen(const char *str);
int     is_csp(char c);
int     is_diouxX(char c);
int     first_flag(char c);
int     is_number(char c);
int     count_length(int n);
int     format_print_di(int arg, char *str, int start, int end);
int     format_print_c(char arg, char *str, int start, int end);


typedef struct s_list t_list;

struct s_list
{
	int zero;
	int hash;
	int min;
	int plus;
	int space;
	int width;
	int precision;
};

t_list	zero_struct();
t_list  fill_struct(t_list a, int *i, char *str);
void    format_width_c(t_list a);

#endif
