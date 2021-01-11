/*
** EPITECH PROJECT, 2020
** create_window
** File description:
** create and display a hunt->window
*/

#include "libmy.h"
#include "hunter.h"

void display_sprite(hunt_t *hunt)
{
    sfSprite_setTexture(hunt->asteroid_s, hunt->asteroid_t, sfFalse);
    sfRenderWindow_drawSprite(hunt->window, hunt->asteroid_s, NULL);
    sfSprite_setTextureRect(hunt->exp_s, hunt->rect);
    sfSprite_setTexture(hunt->exp_s, hunt->exp_t, sfFalse);
    sfRenderWindow_drawSprite(hunt->window, hunt->exp_s, NULL);
}

void move_asteroid(hunt_t *hunt)
{
    if ((hunt->position.x == -100 || hunt->position.y == 1080)
|| hunt->position.y == 0) {
        hunt->position.x = 1920 + 40;
        hunt->position.y = rand() % (700 + 1 - 200) + 200;
        hunt->random_angle = rand() % (7 + 1 - (-7)) + (-7);
    } else {
        hunt->position.x += -10;
        hunt->position.y += hunt->random_angle;
    }
    hunt->rotation += 3;
    sfSprite_setPosition(hunt->asteroid_s, hunt->position);
    sfSprite_setRotation(hunt->asteroid_s, hunt->rotation);
}

void manage_mouse_click(hunt_t *hunt)
{
    sfVector2f ast_pos = sfSprite_getPosition(hunt->asteroid_s);
    sfVector2f reset = {1920 + 40, hunt->random_spawn};
    sfVector2i m_pos = sfMouse_getPositionRenderWindow(hunt->window);

    if ((m_pos.x >= ast_pos.x - 90 && m_pos.x <= ast_pos.x + 90)
&& m_pos.y >= ast_pos.y - 90 && m_pos.y <= ast_pos.y + 90) {
        sfSprite_setPosition(hunt->asteroid_s, reset);
        sfSprite_setPosition(hunt->exp_s, ast_pos);
        hunt->random_angle = rand() % (10 + 1 - (-10)) + (-10);
        hunt->position.x = 1920 + 40;
        hunt->position.y = rand() % (1080 + 1 - 0) + 0;
        hunt->score += 1;
        sfSound_play(hunt->miss);
    } else if ((m_pos.x >= 920 && m_pos.x <= 1100 && m_pos.y >= 450 &&
m_pos.y <= 600) && hunt->move == 0) {
        hunt->move = 1;
        sfSound_play(hunt->click);
    }
}

void analyse_events(hunt_t *hunt)
{
    if (hunt->event.type == sfEvtMouseButtonPressed) {
        manage_mouse_click(&*hunt);
    }
}

int main (int ac, char **av)
{
    hunt_t hunt = init_hunt(hunt);

    game_setup(&hunt, ac, av);
    while (sfRenderWindow_isOpen(hunt.window) && hunt.h == 0) {
        sfRenderWindow_display(hunt.window);
        clock_manager(&hunt);
        sfRenderWindow_clear(hunt.window, sfBlack);
        game_loop(&hunt);
        score_manager(&hunt);
        while (sfRenderWindow_pollEvent(hunt.window, &hunt.event)) {
            analyse_events(&hunt);
            if ((hunt.event.type == sfEvtClosed)
|| hunt.event.key.code == sfKeyEscape) {
                sfRenderWindow_close(hunt.window);
                print_score(hunt.score, hunt.hs);
            }
        }
    }
    destroy_components(hunt);
    return (0);
}