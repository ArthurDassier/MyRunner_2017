/*
** EPITECH PROJECT, 2017
** runner.h
** File description:
** blabla
*/


#ifndef RUNNER_H
#define RUNNER_H

#include "my.h"

enum nom {
	ZOMBIE,
	BACKGROUND,
	BLOCK_STONE,
	BLOCK_DIRT,
	BLOCK_WOOD
};

typedef struct wind
{
	sfVideoMode	video_mode;
	sfRenderWindow	*window;
	sfTime		time_s;
} wind;

typedef struct background
{
	sfTexture	*back_txt;
	sfSprite	*back_spt;
} background;

typedef struct graphs
{
	sfTexture	*grass;
	sfTexture	*cobble;
	sfTexture	*wood;
	sfTexture	*zombie;
	sfSprite	*dead;
	sfSprite	*dirt;
	sfSprite	*stone;
	sfSprite	*woody;
	sfVector2f	map_pos;
	sfVector2f	zomb_pos;
	sfIntRect	animation[24];
} graphs;

typedef struct sounds
{
	sfMusic	*zikmu;
} sounds;

typedef struct game_s
{
	wind		wd;
	background	*bg;
	graphs		*gh;
	sounds		*sd;
	int		anm;
} game_s;

typedef struct game_obj
{
	sfTexture	*texture;
	sfSprite	*sprite;
	sfVector2f	vecteur;
	sfIntRect	rect;
} game_obj;

void analyse_event(game_s game);
void general_init(game_s *game);
void init_game(game_s *game);
void init_graphs(game_s *game);
void read_map(game_s *game, char *str);
void display_map(game_s game, char *str);
void number_map(game_s *game, char *buffer, int i);
void init_tab(game_s *game);
sfIntRect position_pixels(int a, int b, int c, int d);
void animation(game_s *game);
void jump(game_s *game, int jump_dwn);
void check_collision(game_s *game);

#endif
