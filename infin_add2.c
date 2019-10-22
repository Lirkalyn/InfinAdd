/*
** EPITECH PROJECT, 2019
** infin_add2
** File description:
** yolo2
*/

#include <stdlib.h>
#include <stddef.h>
//#include <stdio.h>
#include "display.c"

int abs(int num)
{
    if (num < 0)
        return (num * (-1));
    else
        return num;
}

int *add(int *num1, int *num2, int *res, int len)
{
    int carry[(len + 1)];
    int tmp;
    int i;

    for (i = 0; i <= (len + 1); i++) {
        carry[i] = 0;
        res[i] = 0;
    }
    for (i = len; i >= 0; i--) {
        tmp = (num1[i] + num2[i] + carry[(i + 1)]);
        if (tmp >= 10) {
            res[(i + 1)] = (tmp % 10);
            carry[i] = 1;
        }
        else
            res[(i + 1)] = tmp;
    }
    res[(i + 1)] = carry[(i + 1)];
}

int *sub(int *num1, int *num2, int *res, int len)
{
    int carry[(len + 1)];
    int tmp;
    int i;

    for (i = 0; i <= (len + 1); i++) {
        carry[i] = 0;
        res[i] = 0;
    }
    for (i = len; i >= 0; i--) {
        tmp = (num1[i] + num2[i] - carry[(i + 1)]);
        if (tmp < 0 && (num1[i] > 0 || num2[i] > 0))
            if (abs(num1[i]) < abs(num2[i])) {
                tmp = ((num1[i] + 10) + num2[i] - carry[(i + 1)]);
                carry[i] = 1;
            }
            else if (abs(num2[i]) < abs(num1[i])) {
                tmp = (num1[i] + (num2[i] + 10) - carry[(i + 1)]);
                carry[i] = 1;
            }
        else if (abs(tmp) > 10) {
            tmp %= 10;
            carry[i] = 1;
        }
        res[(i + 1)] = abs(tmp);
    }
}

void my_fork(int *num1, int *num2, int len, int isneg)
{
    int res[(len + 1)];
    int i;

    if (isneg == 0)
        add(num1, num2, res, len);
    else
        sub(num1, num2, res, len);
    display(res, len, isneg);
}