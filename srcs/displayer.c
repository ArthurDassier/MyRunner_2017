/*
** EPITECH PROJECT, 2017
** displayer.c
** File description:
** blabla
*/

#include "my.h"

void number_map(game_s *game, char *buffer, int i)
{
	if (buffer[i] == '1') {
		sfRenderWindow_drawSprite(game->wd.window, game->gh->dirt, NULL);
		sfSprite_setPosition(game->gh->dirt, game->gh->map_pos);
		game->gh->map_pos.x = game->gh->map_pos.x + 98;
	} else if (buffer[i] == '2') {
		sfRenderWindow_drawSprite(game->wd.window, game->gh->stone, NULL);
		sfSprite_setPosition(game->gh->stone, game->gh->map_pos);
		game->gh->map_pos.x = game->gh->map_pos.x + 98;
	} else if (buffer[i] == '3') {
		sfRenderWindow_drawSprite(game->wd.window, game->gh->woody, NULL);
		sfSprite_setPosition(game->gh->woody, game->gh->map_pos);
		game->gh->map_pos.x = game->gh->map_pos.x + 98;
	}
}
