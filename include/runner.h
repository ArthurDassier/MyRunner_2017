/*
** EPITECH PROJECT, 2017
** runner.h
** File description:
** blabla
*/


#ifndef RUNNER_H
#define RUNNER_H

#include "my.h"

typedef struct game_s
{
	sfVideoMode	video_mode;
	sfRenderWindow	*window;
	sfTime		time_s;
} game_s;

typedef struct graphs
{
	sfTexture	*backgrd;
	sfTexture	*grass;
	sfTexture	*cobble;
	sfSprite	*back_grd;
	sfSprite	*dirt;
	sfSprite	*stone;
	sfVector2f	map_pos;
} graphs;

void analyse_event();
void general_init(game_s *game, graphs *graph);
game_s *init_game(game_s *game);
graphs *init_graphs(graphs *graph);
void read_map(game_s *game, graphs *graph, char str[8]);

#endif
