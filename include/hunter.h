/*
** EPITECH PROJECT, 2020
** hunter.h
** File description:
** hunter header file
*/

#ifndef HUNTER_H_
#define HUNTER_H_

#include <SFML/Config.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
typedef struct hunt_s {
    int width;
    int height;
    int bitsPerPixel;
    int move;
    int h;
    float rotation;
    int score;
    int hs;
    int random_spawn;
    int random_angle;
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfMusic *ambient;
    sfSoundBuffer *click_sb;
    sfSound *click;
    sfSoundBuffer *hit_sb;
    sfSound *hit;
    sfSoundBuffer *complete_sb;
    sfSound *complete;
    sfSoundBuffer *miss_sb;
    sfSound *miss;
    sfEvent event;
    sfTexture *asteroid_t;
    sfTexture *crosshair_t;
    sfTexture *background_t;
    sfTexture *exp_t;
    sfSprite *asteroid_s;
    sfSprite *background_s;
    sfSprite *crosshair_s;
    sfSprite *exp_s;
    sfTexture *bg_two_t;
    sfSprite *bg_two_s;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
    sfVector2f position;
    sfVector2f scale;
    sfVector2f scale_two;
    sfVector2f origin;
    sfVector2f origin_two;
    sfVector2f fixed_respawn;
    sfVector2i mouse_pos_i;
    sfVector2f mouse_pos_f;
    float seconds;
} hunt_t;

hunt_t init_hunt(hunt_t);
void print_h(void);
void print_score(int, int);
void move_rect(sfIntRect *, int, int, hunt_t *);
void game_setup(hunt_t *, int, char **);
void destroy_components(hunt_t);
void clock_manager(hunt_t *);
void game_loop(hunt_t *);
void display_sprite(hunt_t *);
void move_asteroid(hunt_t *);
void score_manager(hunt_t *);
void help_flag(hunt_t *, int, char **);

#endif /* !HUNTER_H_ */
