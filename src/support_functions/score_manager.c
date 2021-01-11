/*
** EPITECH PROJECT, 2020
** score_manager
** File description:
** manage score
*/

#include "libmy.h"
#include "hunter.h"

void score_manager(hunt_t *hunt)
{
    if (hunt->score == 20) {
        sfSprite_setPosition(hunt->asteroid_s, hunt->fixed_respawn);
        sfSound_play(hunt->complete);
        hunt->hs = 20;
        hunt->score = 0;
        hunt->move = 0;
    }
}