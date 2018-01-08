/*
** EPITECH PROJECT, 2017
** init.c
** File description:
** blabla
*/

#include "my.h"

void general_init(game_s *game)
{
	init_game(game);
	init_graphs(game);
	sfSprite_setTexture(game->mn->starter, game->mn->menu_start, sfTrue);
	sfSprite_setTexture(game->mn->cutter, game->mn->sword, sfTrue);
	sfSprite_setTexture(game->gh->dead, game->gh->zombie, sfTrue);
	sfSprite_setTexture(game->bg->back_spt, game->bg->back_txt, sfTrue);
	init_tab(game);
	//sfRenderWindow_setMouseCursorVisible(game->wd.window, sfFalse);
	game->gh->zomb_pos.y = 460;
}

void init_game(game_s *game)
{
	game->wd.time_s.microseconds = FRAMERATE;
	game->wd.video_mode.width = WIDTH_WID;
	game->wd.video_mode.height = HEIGHT_WID;
	game->wd.video_mode.bitsPerPixel = BPP;
	game->sd->zikmu = sfMusic_createFromFile("./sounds/28d.wav");
	sfMusic_play(game->sd->zikmu);
	game->wd.window = sfRenderWindow_create(game->wd.video_mode, "MyWindow",
	sfDefaultStyle, NULL);
}

void init_graphs(game_s *game)
{
	txt_create(game);
	txt_menus_creates(game);
	spt_create(game);
	game->anm = 0;
}
