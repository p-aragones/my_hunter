/*
** EPITECH PROJECT, 2020
** move_rect
** File description:
** move rect to only display one sprite
*/

#include <SFML/Graphics.h>
#include "libmy.h"
#include "hunter.h"

void move_rect(sfIntRect *rect, int offset, int max_value, hunt_t *hunt)
{
    rect->left += offset;
    if (rect->left == max_value) {
        rect->left = 0;
        rect->top += 64;
    }
    if (rect->top == 320) {
        rect->top = 0;
        sfSprite_setPosition(hunt->exp_s, hunt->fixed_respawn);
    }
}
