/*
** EPITECH PROJECT, 2020
** game_setup.c
** File description:
** initial game setup
*/

#include "hunter.h"

void game_setup(hunt_t *hunt, int ac, char **av)
{
    help_flag(&*hunt, ac, av);
    sfSprite_setScale(hunt->exp_s, hunt->scale_two);
    sfSprite_setOrigin(hunt->exp_s, hunt->origin_two);
    sfSprite_setPosition(hunt->exp_s, hunt->position);
    sfSprite_setOrigin(hunt->asteroid_s, hunt->origin);
    sfSprite_setPosition(hunt->asteroid_s, hunt->position);
    sfSprite_scale(hunt->asteroid_s, hunt->scale);
    sfSprite_setOrigin(hunt->asteroid_s, hunt->origin);
    sfMusic_play(hunt->ambient);
    sfMusic_setVolume(hunt->ambient, 100);
    sfMusic_setLoop(hunt->ambient, sfTrue);
    sfRenderWindow_setFramerateLimit(hunt->window, 30);
}