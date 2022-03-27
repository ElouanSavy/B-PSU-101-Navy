/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** my.h
*/

#ifndef TEST_MY
    #define TEST_MY

    #include <stdarg.h>
    #include <stdlib.h>

int my_compute_power_rec(int nb, int p);

int my_compute_square_root(int nb);

int my_find_prime_sup(int nb);

int my_getnbr(char const *str);

int my_isneg(int n);

int my_is_prime(int nb);

void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

char *my_revstr(char *str);

int my_showmem(char const *str, int size);

int my_showstr(char const *str);

void my_sort_int_array(int *array, int size);

char *my_strcapitalize(char *str);

char *my_strcat(char *dest, char const *src);

int my_strcmp(char const *s1, char const *s2);

char *my_strcpy(char *dest, char const *src);

int my_str_isalpha(char const *str);

int my_str_islower(char const *str);

int my_str_isnum(char const *str);

int my_str_isprintable(char const *str);

int my_str_isupper(char const *str);

int my_strlen(char const *str);

char *my_strlowcase(char *str);

char *my_strncat(char *dest, char const *src, int nb);

int my_strncmp(char const *s1, char const *s2, int n);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strstr(char *str, char const *to_find);

char *my_strupcase(char *str);

void my_swap(int *a, int *b);

char **my_str_to_word_array(char const *str);

char *my_strdup(char const *src);

long convert_to_int(char const *str, int min, int max, int negative);

void get_number_index(char const *str, int *min, int *max);

int count_negative(char const *str, int min);

int find_divisor(int nb);

void check_number(int *array, int size,  int index);

int count_word(char const *str);

int is_alphanumeric(char c);

char *save_word(char const *str, int *i);

int my_printf(const char *format, ...);

int my_putnbr_base(int nbr, char const *base);

int my_putunbr_base(unsigned int nbr, char const *base);

char *format_number(const char *format, int *i);

void display_detailed_str(char *str);

void uint_flags_handler(const char *format, va_list params, int *);

void char_flags_handler(const char *format, va_list params, int *);

void format_flags_handler(const char *format, va_list params, int *);

void display_decimal(const char *format, va_list params, int *);

int check_flag(char const *flag, va_list params, int *);

void hashtag_flags_handler(const char *format, va_list params, int *);

void print_zero(int zero, int *size);

void count_print_digits(char digit, int *size);

void long_flag(const char *format, va_list params, int *index);

void short_flag(const char *format, va_list params, int *index);

int my_putsnbr_base(short int nbr, char const *base);

int my_putlnbr_base(long int nbr, char const *base);

unsigned long int my_compute_long_power_rec(long int nb , long int p);

int my_putlunbr_base(long unsigned int nbr, char const *base);

int my_putsunbr_base(unsigned short int nbr, char const *base);

void display_pointer_address(const char *format, va_list params, int *index);

typedef struct flags {
    char flag;
    void (*flags_func)(const char *, va_list, int *);
} flags;

#endif
