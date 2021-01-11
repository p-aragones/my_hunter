/*
** EPITECH PROJECT, 2020
** clock_manager
** File description:
** manage clock
*/

#include "libmy.h"
#include "hunter.h"

void clock_manager(hunt_t *hunt)
{
    hunt->time = sfClock_getElapsedTime(hunt->clock);
    hunt->seconds = hunt->time.microseconds / 1000000.0;
    if (hunt->seconds >= 0.01) {
        move_rect(&hunt->rect, 64, 512, &*hunt);
        sfClock_restart(hunt->clock);
    }
}