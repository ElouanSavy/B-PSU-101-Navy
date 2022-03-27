/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_printf
*/

#include "my.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

const flags flags_handler[] = {
    {'d', &display_decimal},
    {'c', &char_flags_handler},
    {'s', &char_flags_handler},
    {'C', &char_flags_handler},
    {'S', &char_flags_handler},
    {'i', &display_decimal},
    {'b', &uint_flags_handler},
    {'x', &uint_flags_handler},
    {'X', &uint_flags_handler},
    {'o', &uint_flags_handler},
    {'p', &display_pointer_address},
    {'u', &uint_flags_handler},
    {'#', &hashtag_flags_handler},
    {'%', &char_flags_handler},
    {' ', &format_flags_handler},
    {'+', &format_flags_handler},
    {'l', &long_flag},
    {'h', &short_flag},
    {'\0', NULL}
};

void uint_flags_handler(const char *format, va_list params, int *index)
{
    switch (format[1]) {
    case 'b':
        my_putunbr_base(va_arg(params, unsigned int), "01");
        break;
    case 'u':
        my_putunbr_base(va_arg(params, unsigned int), "0123456789");
        break;
    case 'o':
        my_putunbr_base(va_arg(params, unsigned int), "01234567");
        break;
    case 'x':
        my_putunbr_base(va_arg(params, unsigned int), "0123456789abcdef");
        break;
    case 'X':
        my_putunbr_base(va_arg(params, unsigned int), "0123456789ABCDEF");
        break;
    default:
    }
}

void char_flags_handler(const char *format, va_list params, int *index)
{
    switch (format[1]) {
    case 's':
        my_putstr(va_arg(params, char *));
        break;
    case 'C':
    case 'c':
        my_putchar((char)va_arg(params, int));
        break;
    case '%':
        my_putchar('%');
        break;
    case 'S':
        display_detailed_str(va_arg(params, char *));
        break;
    default:
        break;
    }
}

int check_flag(char const *flag, va_list params, int *index)
{
    int i = 0;

    while (flags_handler[i].flag != '\0') {
        if (flags_handler[i].flag == flag[1]) {
            flags_handler[i].flags_func(flag, params, index);
            return (0);
        }
        i += 1;
    }
    if (flags_handler[i].flag == '\0') {
        my_putchar(flag[0]);
        my_putchar(flag[1]);
    }
    return (0);
}

int my_printf(const char *format, ...)
{
    int i = 0;
    va_list params;

    va_start(params, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            check_flag(&format[i], params, &i);
            i += 1;
        } else {
            my_putchar(format[i]);
        }
        i += 1;
    }
    va_end(params);
    return (0);
}
