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
	sfSprite_setTexture(game->gh->dead, game->gh->zombie, sfTrue);
	sfSprite_setTexture(game->bg->back_spt, game->bg->back_txt, sfTrue);
	init_tab(game);
	game->gh->zomb_pos.y = 350;
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
	game->bg->back_txt = sfTexture_createFromFile("./textures/index.png",
	NULL);
	game->gh->grass = sfTexture_createFromFile("./textures/graas_mine.png",
	NULL);
	game->gh->cobble = sfTexture_createFromFile("./textures/cobble.png",
	NULL);
	game->gh->wood = sfTexture_createFromFile("./textures/wood.png",
	NULL);
	game->gh->zombie = sfTexture_createFromFile("./textures/zombie.png",
	NULL);
	game->bg->back_spt = sfSprite_create();
	game->gh->dirt = sfSprite_create();
	game->gh->dead = sfSprite_create();
	game->gh->stone = sfSprite_create();
	game->gh->woody = sfSprite_create();
	game->anm = 0;
}
