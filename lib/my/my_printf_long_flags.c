/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-elouan.savy-camaret
** File description:
** my_printf_long_flags
*/

#include "my.h"

void long_flag_base(const char *format, va_list params, int *index);

void short_flag_base(const char *format, va_list params, int *index);

void long_flag(const char *format, va_list params, int *index)
{
    *index += 1;
    switch (format[2]) {
    case 'i':
    case 'd':
        my_putlnbr_base(va_arg(params, long int), "0123456789");
        break;
    default:
        long_flag_base(format, params, index);
        break;
    }
}

void long_flag_base(const char *format, va_list params, int *index)
{
    switch (format[2]) {
    case 'b':
        my_putlunbr_base(va_arg(params, long int), "01");
        break;
    case 'u':
        my_putlunbr_base(va_arg(params, long int), "0123456789");
        break;
    case 'o':
        my_putlunbr_base(va_arg(params, long int), "01234567");
        break;
    case 'x':
        my_putlunbr_base(va_arg(params, long int), "0123456789abcdef");
        break;
    case 'X':
        my_putlunbr_base(va_arg(params, long int), "0123456789ABCDEF");
        break;
    default:
        check_flag(&format[1], params, index);
        break;
    }
}

void short_flag(const char *format, va_list params, int *index)
{
    *index += 1;
    switch (format[2]) {
    case 'i':
    case 'd':
        my_putsnbr_base(va_arg(params, int), "0123456789");
        break;
    default:
        short_flag_base(format, params, index);
        break;
    }
}

void short_flag_base(const char *format, va_list params, int *index)
{
    switch (format[2]) {
    case 'b':
        my_putsunbr_base(va_arg(params, int), "01");
        break;
    case 'u':
        my_putsunbr_base(va_arg(params, int), "0123456789");
        break;
    case 'o':
        my_putsunbr_base(va_arg(params, int), "01234567");
        break;
    case 'x':
        my_putsunbr_base(va_arg(params, int), "0123456789abcdef");
        break;
    case 'X':
        my_putsunbr_base(va_arg(params, int), "0123456789ABCDEF");
        break;
    default:
        check_flag(&format[1], params, index);
        break;
    }
}

void display_pointer_address(const char *format, va_list params, int *index)
{
    my_putunbr_base(va_arg(params, unsigned int), "0123456789abcdef");
}
