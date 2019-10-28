cmake_minimum_required(VERSION 3.14)
project(gsprintf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(gsprintf
        format_print_di.c
        ft_printf.c
        ft_printf.h
        libft.c
        main.c
        min_absent.c
        min_present_di.c)
