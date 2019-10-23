cmake_minimum_required(VERSION 3.15)
project(clearprintf C)

set(CMAKE_C_STANDARD 99)

add_executable(clearprintf main.c ft_printf.c ft_printf.h print_pointer.c libft.c check_format.c format_print_di.c)