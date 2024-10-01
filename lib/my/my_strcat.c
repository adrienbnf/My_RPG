/*
** EPITECH PROJECT, 2023
** my str cat
** File description:
** ..
*/
#include "my.h"

char *my_strcat(char *str, const char *fus)
{
    int i = 0;
    int j = 0;
    int t = 0;
    int len_total = my_strlen(str) + my_strlen(fus);
    char *mot = malloc(sizeof(char) * (len_total + 1));

    while (i != len_total) {
        if (str[j] != '\0') {
            mot[i] = str[j];
            j++;
        } else {
            mot[i] = fus[t];
            t++;
        }
        i++;
    }
    mot[i] = '\0';
    return mot;
}
