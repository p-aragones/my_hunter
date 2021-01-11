/*
** EPITECH PROJECT, 2020
** print_score
** File description:
** print score or highest score
*/

#include "libmy.h"

void print_score(int score, int hs)
{
    my_putstr("========================================\n");
    my_putstr("(Highest) Score: ");
    if (hs == 20) {
        my_put_nbr(hs);
        my_putstr("/20\n");
    } else {
        my_put_nbr(score);
        my_putstr("/20\n");
    }
    if (hs == 20 || score == 20)
        my_putstr("Task completed!\n");
    else
        my_putstr("Mission failed, we'll get 'em next time!\n");
    my_putstr("========================================\n");
}