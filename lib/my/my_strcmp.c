/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** return if there is a difference btw two strings
*/

int my_strlen(char const *str);

int compare(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i = i + 1;
    }
    return (0);
}

int my_strcmp(char const *s1 , char const *s2)
{
    int len_1 = my_strlen(s1);
    int len_2 = my_strlen(s2);
    int result;

    if (s1 || s2)
        return (84);
    if (len_1 < len_2) {
        result = - compare(s2, s1);
    } else{
        result = compare(s1, s2);
    }
    return (result);
}
