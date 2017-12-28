/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** blabla
*/

#include "my.h"

void general_init(game_s *game, graphs *graph)
{
	init_game(game);
	init_graphs(graph);
	sfSprite_setTexture(graph->back_grd, graph->backgrd, sfTrue);
}

game_s *init_game(game_s *game)
{
	game->time_s.microseconds = FRAMERATE;
	game->video_mode.width = WIDTH_WID;
	game->video_mode.height = HEIGHT_WID;
	game->video_mode.bitsPerPixel = BPP;
	game->window = sfRenderWindow_create(game->video_mode, "MyWindow",
	sfDefaultStyle, NULL);
	return (game);
}

graphs *init_graphs(graphs *graph)
{
	graph->backgrd = sfTexture_createFromFile("./textures/index.png",
	NULL);
	graph->grass = sfTexture_createFromFile("./textures/graas_mine.png",
	NULL);
	graph->cobble = sfTexture_createFromFile("./textures/cobble.png",
	NULL);
	graph->back_grd = sfSprite_create();
	graph->dirt = sfSprite_create();
	graph->stone = sfSprite_create();
	return (graph);
}
