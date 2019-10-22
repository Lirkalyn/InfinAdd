/*
** EPITECH PROJECT, 2019
** infin_add
** File description:
** yoloh
*/

#ifndef STONCKS_H_
#define STONCKS_H_

int isitneg(const char *av[], int len_num1, int len_num2, int *isneg);
void fill_up(int len, int len_numx, int *numx, const char *num_str);
void fill_0(int len, int *num1, int *num2);
void infin_add(int ac, const char *av[]);
int abs(int num);
int inf(int *num1, int *num2, int len);
int *add(int *num1, int *num2, int *res, int len);
int *sub(int *num1, int *num2, int *res, int len);
void my_fork(int *num1, int *num2, int len, int isneg);
void display(int *res, int len, int isneg);

#endif
