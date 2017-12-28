/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** blabla
*/

#include "my.h"

void read_map(game_s *game, graphs *graph, char str[8])
{
	int	i = 0;
	graph->map_pos.x = 0;
	graph->map_pos.y = 0;

	while (i != 8) {
		if (str[i] == '1') {
			sfRenderWindow_drawSprite(game->window, graph->dirt, NULL);
			sfSprite_setPosition(graph->dirt, graph->map_pos);
			graph->map_pos.x = graph->map_pos.x + 100;
		} else if (str[i] == '2') {
			sfRenderWindow_drawSprite(game->window, graph->stone, NULL);
			sfSprite_setPosition(graph->stone, graph->map_pos);
			graph->map_pos.x = graph->map_pos.x + 100;

		} else
			graph->map_pos.x = graph->map_pos.x + 100;
		++i;
	}
}
