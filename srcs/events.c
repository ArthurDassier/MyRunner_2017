/*
** EPITECH PROJECT, 2017
** events.c
** File description:
** blabla
*/

#include "my.h"

void analyse_event(game_s game)
{
	sfEvent	event;
	while (sfRenderWindow_pollEvent(game.window, &event)) {
		if (event.type == sfEvtClosed) {
			my_printf("pfff, looser.\n");
			sfRenderWindow_close(game.window);
		}
	}
}
