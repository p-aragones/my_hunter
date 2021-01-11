/*
** EPITECH PROJECT, 2020
** destroy_components
** File description:
** destroy
*/

#include "hunter.h"

void destroy_components(hunt_t hunt)
{
    sfSoundBuffer_destroy(hunt.miss_sb);
    sfSound_destroy(hunt.miss);
    sfMusic_destroy(hunt.ambient);
    sfSoundBuffer_destroy(hunt.click_sb);
    sfSound_destroy(hunt.click);
    sfSoundBuffer_destroy(hunt.complete_sb);
    sfSound_destroy(hunt.complete);
    sfRenderWindow_destroy(hunt.window);
    sfTexture_destroy(hunt.crosshair_t);
    sfSprite_destroy(hunt.crosshair_s);
    sfTexture_destroy (hunt.asteroid_t);
    sfSprite_destroy(hunt.asteroid_s);
    sfTexture_destroy (hunt.background_t);
    sfSprite_destroy(hunt.background_s);
    sfTexture_destroy(hunt.exp_t);
    sfSprite_destroy(hunt.exp_s);
    sfClock_destroy(hunt.clock);
}