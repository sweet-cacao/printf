#ifndef CLEARPRINTF_FT_PRINTF_H
#define CLEARPRINTF_FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
    int zero;
    int hash;
    int min;
    int plus;
    int space;
    int width;
    int precision;
    char *modifier;
}t_list;

void    print_pointer(const void *addr);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_printf(char *format, ...);
void	ft_putstr(char *s);
int     is_csp(char c);
int     is_diouxX(char c);
int     first_flag(char c);
int     is_number(char c);
int     count_length(int n);
void    format_print_di(int arg, char *str, int start, int end);
void    min_absent(int arg, int len_arg, t_list a);
void    min_present(int arg, int len_arg, t_list a);
void    ft_bzero(void *s, size_t n);
char    *ft_strnew(size_t size);
int     is_modifier(char c);
char    *ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);

t_list	zero_struct();

#endif