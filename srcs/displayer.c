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
		sfRenderWindow_drawSprite(game->wd.window, game->graph->dirt, NULL);
		sfSprite_setPosition(game->graph->dirt, game->graph->map_pos);
		game->graph->map_pos.x = game->graph->map_pos.x + 98;
	} else if (buffer[i] == '2') {
		sfRenderWindow_drawSprite(game->wd.window, game->graph->stone, NULL);
		sfSprite_setPosition(game->graph->stone, game->graph->map_pos);
		game->graph->map_pos.x = game->graph->map_pos.x + 98;
	} else if (buffer[i] == '3') {
		sfRenderWindow_drawSprite(game->wd.window, game->graph->woody, NULL);
		sfSprite_setPosition(game->graph->woody, game->graph->map_pos);
		game->graph->map_pos.x = game->graph->map_pos.x + 98;
	}
}
