/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** yolo
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include "include/infinadd.h"

int isitneg(const char *av[], int len_num1, int len_num2, int *isneg)
{
    int i;

    if ((av[1][0] == '-' && (len_num1 - 1) > len_num2)) {
        *isneg += 1;
    }
    else if ((av[2][0] == '-' && (len_num2 - 1) > len_num1)) {
        *isneg += 1;
    }
    else
        for (i = 0; i < len_num1; i++) {
            if (av[1][0] == '-' && av[1][(i + 1)] > av[2][i]){
                *isneg += 1;
                }
            else if (av[2][0] == '-' && av[2][(i + 1)] > av[1][i]) {
                *isneg += 1;
            }
            else
                return 0;
        }
}

void fill_up(int len, int len_numx, int *numx, const char *num_str)
{
    for (;len_numx >= 0;)
    {
        if (num_str[len_numx] >= '0' && num_str[len_numx] <= '9')
            if (num_str[0] == '-')
                numx[len] = ((num_str[len_numx] - '0') * (-1));
            else
                numx[len] = (num_str[len_numx] - '0');
        len--;
        len_numx--;
    }
}

void fill_0(int len, int *num1, int *num2)
{
    int i;

    for (i = 0; i < len; i++)
    {
        num1[i] = 0;
    }
    for (i = 0; i < len; i++)
    {
        num2[i] = 0;
    }
}

void infin_add(int ac, const char *av[])
{
    int *num1;
    int *num2;
    int len_num1;
    int len_num2;
    int len;
    int isneg = 0;

    for (len_num1 = 0; av[1][len_num1] != '\0'; len_num1 += 1);
    for (len_num2 = 0; av[2][len_num2] != '\0'; len_num2 += 1);
    len = (len_num1 > len_num2) ? len_num1 : len_num2;
    isitneg(av, len_num1, len_num2, &isneg);
    if (isneg == 0 && (av[1][0] == '-' || av[2][0] == '-'))
        isneg -= 1;
    num1 = (int *)malloc(len * sizeof(int));
    num2 = (int *)malloc(len * sizeof(int));
    fill_0(len, num1, num2);
    fill_up(len, len_num1, num1, av[1]);
    fill_up(len, len_num2, num2, av[2]);
    my_fork(num1, num2, len, isneg);
}

int main(int argc, const char *argv[])
{
    if (argv[1] == NULL || argv[2] == NULL)
        return 84;
    infin_add(argc, argv);
    return 0;
}