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
	sfTexture	*defeat;
	sfTexture	*win;
	sfSprite	*starter;
	sfSprite	*cutter;
	sfSprite	*def;
	sfSprite	*vic;
	sfVector2f	swd_pos;
} menus;

typedef struct wind
{
	sfVideoMode	video_mode;
	sfRenderWindow	*window;
	sfTime		time_s;
	sfFont		*font;
	sfText		*text;
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
	sfVector2f	pos_map[1000];
	sfIntRect	animation[24];
} graphs;

typedef struct sounds
{
	sfMusic		*zikmu;
	sfSoundBuffer	*zombos;
	sfSoundBuffer	*epee;
	sfSound		*zmb;
	sfSound		*epe;
} sounds;

typedef struct status_game
{
	int		score;
	int		anm;
	int		status;
	int		map;
	int		check;
	int		jump;
	int		sol;
	int		jump_up;
	int		jump_dwn;
} status_game;

typedef struct game_s
{
	wind		wd;
	background	*bg;
	graphs		*gh;
	sounds		*sd;
	menus		*mn;
	status_game	st;
} game_s;

sfIntRect position_pixels(int a, int b, int c, int d);
void number_map(game_s *game, char *buffer, int i, int count);
void display_code(game_s *game, char *buffer);
void display_map(game_s *game, char *str);
void read_map(game_s *game, char *str);
void return_enter(game_s *game, int status);
void txt_menus_creates(game_s *game);
void draw_background(game_s *gm);
void general_init(game_s *game);
void analyse_event(game_s game);
void init_graphs(game_s *game);
void animation(game_s *game);
void spt_create(game_s *game);
void txt_create(game_s *game);
void display_start(game_s *game);
void init_game(game_s *game);
void init_tab(game_s *game);
void init_sounds(game_s *game);
void defeat_menu(game_s *game);
void win_menu(game_s *game);
int key_enter(game_s *game);
int jump(game_s *game);
void score_n_map(game_s *game);
void destroyer(game_s *game, char *buffer);
void destroy_text(game_s *game);
void destroy_sprt(game_s *game);
void destroy_snds(game_s *game);
void win_or_def(game_s *game);
void reset(game_s *game);
char *my_return_str(int i, char *b);
void my_score(game_s *game);
void help(void);

#endif
