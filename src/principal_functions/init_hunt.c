/*
** EPITECH PROJECT, 2020
** init_hunt
** File description:
** initialize hunt_t struct
*/

#include "libmy.h"
#include "hunter.h"

hunt_t init_hunt_four(hunt_t h)
{
    h.complete_sb = sfSoundBuffer_createFromFile("src/sound/task_Complete.wav");
    h.complete = sfSound_create();
    sfSound_setBuffer(h.complete, h.complete_sb);
    h.miss_sb = sfSoundBuffer_createFromFile("src/sound/miss.ogg");
    h.miss = sfSound_create();
    sfSound_setBuffer(h.miss, h.miss_sb);
    h.click_sb = sfSoundBuffer_createFromFile("src/sound/UI_Select.wav");
    h.click = sfSound_create();
    sfSound_setBuffer(h.click, h.click_sb);
    h.clock = sfClock_create();
    h.rect.top = 0;
    return (h);
}

hunt_t init_hunt_three(hunt_t h)
{
    h.scale.x = 0.15;
    h.scale.y = 0.15;
    h.origin.x = 289;
    h.origin.y = 237;
    h.origin_two.x = 32;
    h.origin_two.y = 32;
    h.fixed_respawn.x = 1920 + 110;
    h.fixed_respawn.y = 540;
    h.mouse_pos_f.x = 0;
    h.mouse_pos_f.y = 0;
    h.mouse_pos_i.x = 0;
    h.mouse_pos_i.y = 0;
    h.rect.left = 0;
    h.rect.width = 64;
    h.rect.height = 64;
    h.position.x = 1920 + 110;
    h.position.y = 540;
    h = init_hunt_four(h);
    return (h);
}

hunt_t init_hunt_two(hunt_t h)
{
    h.asteroid_t = sfTexture_createFromFile("src/images/ast.png", NULL);
    h.asteroid_s = sfSprite_create();
    h.crosshair_t = sfTexture_createFromFile("src/images/crosshair.png", NULL);
    h.crosshair_s = sfSprite_create();
    h.background_t = sfTexture_createFromFile("src/images/bg.jpg", NULL);
    h.background_s = sfSprite_create();
    h.bg_two_t = sfTexture_createFromFile("src/images/bg2.jpg", NULL);
    h.bg_two_s = sfSprite_create();
    h.exp_t = sfTexture_createFromFile("src/images/exp.png", NULL);
    h.exp_s = sfSprite_create();
    h.scale_two.x = 2;
    h.scale_two.y = 2;
    h = init_hunt_three(h);
    return (h);
}

hunt_t init_hunt(hunt_t h) {
    h.width = 1920;
    h.height = 1080;
    h.bitsPerPixel = 32;
    h.move = 0;
    h.h = 0;
    h.rotation = 0;
    h.score = 0;
    h.hs = 0;
    h.random_spawn = rand() % (800 + 1 - 250) + 250;
    h.random_angle = rand() % (7 + 1 - (-7)) + (-7);
    h.video_mode.height = h.height;
    h.video_mode.width = h.width;
    h.video_mode.bitsPerPixel = h.bitsPerPixel;
    h.window = sfRenderWindow_create(h.video_mode, "x", sfFullscreen, NULL);
    h.ambient = sfMusic_createFromFile("src/sound/AMB_Weapons.wav");
    h = init_hunt_two(h);
    return (h);
}