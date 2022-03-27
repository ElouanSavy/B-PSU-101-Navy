/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myprintf-elouan.savy-camaret
** File description:
** my_printf_format
*/

#include "my.h"

void display_decimal(const char *format, va_list params, int *index)
{
    my_put_nbr(va_arg(params, int));
}

void complete_width_char(long nbr, int e_size, char completion)
{
    long size = 1;

    while ((nbr / 10) > 0) {
        nbr /= 10;
        size += 1;
    }
    while (size < e_size) {
        my_putchar(completion);
        size += 1;
    }
}

void display_detailed_str(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            complete_width_char(str[i], 3, '0');
            my_putunbr_base((unsigned int)str[i], "01234567");
        } else {
            my_putchar(str[i]);
        }
        i += 1;
    }
}

void hashtag_flags_handler(const char *format, va_list params, int *index)
{
    *index += 1;
    switch (format[2]) {
    case 'o':
        my_putstr("0");
        break;
    case 'x':
        my_putstr("0x");
        break;
    case 'X':
        my_putstr("0X");
        break;
    default:
        break;
    }
    if (format[2] == 'd' || format[2] == 'i') {
        display_decimal(&format[1], params, index);
    } else
        check_flag(&format[1], params, index);
}

void format_flags_handler(const char *format, va_list params, int *index)
{
    int nbr = 0;

    *index += 1;
    if (format[2] == 'd' || format[2] == 'i') {
        nbr = va_arg(params, int);
        if (nbr > 0 && format[1] == ' ')
            my_putchar(' ');
        if (nbr > 0 && format[1] == '+')
            my_putchar('+');
        my_put_nbr(nbr);
    } else {
        check_flag(&format[1], params, index);
    }
}
