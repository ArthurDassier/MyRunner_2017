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
	sfSprite_setTexture(game->back_rd->back_spt, game->back_rd->back_txt, sfTrue);
}

void init_game(game_s *game)
{
	game->wd.time_s.microseconds = FRAMERATE;
	game->wd.video_mode.width = WIDTH_WID;
	game->wd.video_mode.height = HEIGHT_WID;
	game->wd.video_mode.bitsPerPixel = BPP;
	game->wd.window = sfRenderWindow_create(game->wd.video_mode, "MyWindow",
	sfDefaultStyle, NULL);
}

void init_graphs(game_s *game)
{
	game->back_rd->back_txt = sfTexture_createFromFile("./textures/index.png",
	NULL);
	game->graph->grass = sfTexture_createFromFile("./textures/graas_mine.png",
	NULL);
	game->graph->cobble = sfTexture_createFromFile("./textures/cobble.png",
	NULL);
	game->graph->wood = sfTexture_createFromFile("./textures/wood.png",
	NULL);
	game->back_rd->back_spt = sfSprite_create();
	game->graph->dirt = sfSprite_create();
	game->graph->stone = sfSprite_create();
	game->graph->woody = sfSprite_create();
}
