/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-diego.pintat-gil
** File description:
** print_text
*/

#include "pnj.h"

static void text_tools(text_box_t *box, sfRenderWindow *win,
    float delta, char **tmp)
{
    tmp[box->i][box->index] = '\0';
    if (delta > 0.15) {
        box->index++;
        delta = 0;
    }
    sfText_setString(box->text, tmp[box->i]);
    sfRenderWindow_drawText(win, box->text, NULL);
    if (strlen(box->comment[box->i]) - box->index == 0)
        box->write = 1;
    free(tmp);
}

void print_text(text_box_t *box, sfRenderWindow *win, sfClock *clock)
{
    char **tmp = my_arraydup(box->comment);
    double seconds = sfClock_getElapsedTime(clock).microseconds / 1000000.0;
    static float delta = 0;

    delta += seconds - box->tmp;
    box->tmp = seconds;
    if (box->write == 1) {
        sfRenderWindow_drawText(win, box->text, NULL);
        if (delta > 2 && my_arrlen(tmp) > box->i + 1) {
            box->i++;
            delta = 0;
            box->write = 0;
            box->index = 0;
        }
        return;
    }
    text_tools(box, win, delta, tmp);
    return;
}
