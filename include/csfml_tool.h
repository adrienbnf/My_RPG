/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** Header of the project
*/

#ifndef CSFML_TOOL_H_
    #define CSFML_TOOL_H_
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

sfRectangleShape *create_rectangle(sfVector2f pos, sfVector2f size,
    int show_border, sfColor color);
int rect_are_colliding(sfRectangleShape *rect1, sfRectangleShape *rect2);
#endif /* !RPG_H_ */
