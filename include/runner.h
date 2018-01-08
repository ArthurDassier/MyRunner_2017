/*
** EPITECH PROJECT, 2017
** runner.h
** File description:
** blabla
*/


#ifndef RUNNER_H
#define RUNNER_H

#include "my.h"

typedef struct menus
{
	sfTexture	*menu_start;
	sfTexture	*sword;
	sfSprite	*starter;
	sfSprite	*cutter;
	sfVector2f	swd_pos;
} menus;

typedef struct wind
{
	sfVideoMode	video_mode;
	sfRenderWindow	*window;
	sfTime		time_s;
} wind;

typedef struct background
{
	sfTexture	*back_txt;
	sfTexture	*back_mt3;
	sfTexture	*back_mt2;
	sfTexture	*back_mt1;
	sfSprite	*back_spt;
	sfSprite	*back_spm3;
	sfSprite	*back_spm2;
	sfSprite	*back_spm1;
	sfVector2f	m3_pos;
	sfVector2f	m2_pos;
	sfVector2f	m1_pos;
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
	menus		*mn;
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
void display_map(game_s *game, char *str);
void number_map(game_s *game, char *buffer, int i);
void init_tab(game_s *game);
void txt_create(game_s *game);
void spt_create(game_s *game);
sfIntRect position_pixels(int a, int b, int c, int d);
void animation(game_s *game);
void draw_background(game_s *gm);
int jump();
int display_start(game_s *game);
void display_code(game_s *game, char *buffer);

#endif
