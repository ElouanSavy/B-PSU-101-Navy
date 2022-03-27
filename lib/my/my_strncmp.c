/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** compare two string and return the value of the difference
*/

int my_strlen(char const *str);

int my_strncmp(char const *s1 , char const *s2 , int n)
{
    int i = 0;
    int length_1 = my_strlen(s1);
    int length_2 = my_strlen(s2);

    while (i < n) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i = i + 1;
    }
    return (0);
}
