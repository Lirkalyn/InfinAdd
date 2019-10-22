/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** yolodisplay
*/

#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

void display(int *res, int len, int isneg)
{
    int i;
    char d;
    _Bool zero = 1;

    if (isneg == 1)
        write(1, "-", 1);
    for (i = 0; i <= len; i++) {
        if (res[i] != 0)
            zero = 0;
        if (zero == 0) {
            d = (res[i] + '0');
            write(1, &d, 1);
        }
    }
    write(1, "\n", 2);
}