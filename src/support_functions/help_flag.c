/*
** EPITECH PROJECT, 2020
** help_flag
** File description:
** manage help flag
*/

#include "libmy.h"
#include "hunter.h"

void help_flag(hunt_t *hunt, int ac, char **av)
{
    if (ac >= 2) {
        if (my_strlen(av[1]) == 2) {
            if (my_strcmp(av[1], "-h") == 0) {
                print_h();
                hunt->h = 1;
            }
        }
    }
}