/*
** EPITECH PROJECT, 2020
** game_loop.c
** File description:
** game loop
*/

#include "libmy.h"
#include "hunter.h"

void game_loop(hunt_t *hunt)
{
    if (hunt->move != 0) {
        sfRenderWindow_setMouseCursorVisible(hunt->window, sfFalse);
        hunt->mouse_pos_i = sfMouse_getPositionRenderWindow(hunt->window);
        hunt->mouse_pos_f.x = hunt->mouse_pos_i.x;
        hunt->mouse_pos_f.y = hunt->mouse_pos_i.y;
        sfSprite_setTexture(hunt->bg_two_s, hunt->bg_two_t, sfTrue);
        sfRenderWindow_drawSprite(hunt->window, hunt->bg_two_s, NULL);
        sfSprite_setPosition(hunt->crosshair_s, hunt->mouse_pos_f);
        move_asteroid(&*hunt);
        display_sprite(hunt);
        sfSprite_setTexture(hunt->crosshair_s, hunt->crosshair_t, sfTrue);
        sfRenderWindow_drawSprite(hunt->window, hunt->crosshair_s, NULL);
    } else {
        sfRenderWindow_setMouseCursorVisible(hunt->window, sfTrue);
        sfSprite_setTexture(hunt->background_s, hunt->background_t, sfTrue);
        sfRenderWindow_drawSprite(hunt->window, hunt->background_s, NULL);
    }
}