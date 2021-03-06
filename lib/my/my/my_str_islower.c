/*
** EPITECH PROJECT, 2019
** Str is alpha
** File description:
** Duplicate of the string.h (I think)
*/

int is_digit(char c);

int is_lowercase(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int my_str_islower(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_lowercase(str[i]))
            return (0);
    }
    return (1);
}

int my_str_islower_or_num(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!is_lowercase(str[i]) && !is_digit(str[i]))
            return (0);
    }
    return (1);
}
