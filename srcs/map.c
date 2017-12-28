/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** blabla
*/

#include "my.h"

void display_map(game_s game, char *str)
{
	sfRenderWindow_drawSprite(game.wd.window, game.back_rd->back_spt, NULL);
	sfSprite_setTexture(game.graph->dirt, game.graph->grass, sfTrue);
	sfSprite_setTexture(game.graph->stone, game.graph->cobble, sfTrue);
	sfSprite_setTexture(game.graph->woody, game.graph->wood, sfTrue);
	read_map(&game, str);
}

void read_map(game_s *game, char *buffer)
{
	int	i = 0;

	game->graph->map_pos.x = 0;
	game->graph->map_pos.y = 600;
	while (i != my_strlen(buffer)) {
		if (buffer[i] == '1' || buffer[i] == '2' || buffer[i] == '3')
			number_map(game, buffer, i);
		else if (buffer[i] == '\n') {
			game->graph->map_pos.x = 0;
			game->graph->map_pos.y = game->graph->map_pos.y + 98;
		} else
			game->graph->map_pos.x = game->graph->map_pos.x + 98;
		++i;
	}
}
