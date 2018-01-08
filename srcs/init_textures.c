/*
** EPITECH PROJECT, 2017
** init_textures.c
** File description:
** blabla
*/

#include "my.h"

void txt_create(game_s *game)
{
	game->bg->back_txt = sfTexture_createFromFile("./textures/index.png",
	NULL);
	game->bg->back_mt3 = sfTexture_createFromFile("./textures/m3.png",
	NULL);
	game->bg->back_mt2 = sfTexture_createFromFile("./textures/m2.png",
	NULL);
	game->bg->back_mt1 = sfTexture_createFromFile("./textures/m1.png",
	NULL);
	game->gh->grass = sfTexture_createFromFile("./textures/graas_mine.png",
	NULL);
	game->gh->cobble = sfTexture_createFromFile("./textures/cobble.png",
	NULL);
	game->gh->wood = sfTexture_createFromFile("./textures/wood.png",
	NULL);
	game->gh->zombie = sfTexture_createFromFile("./textures/zombie.png",
	NULL);
}

void txt_menus_creates(game_s *game)
{
	game->mn->menu_start = sfTexture_createFromFile("./textures/menu.png",
	NULL);
	game->mn->sword = sfTexture_createFromFile("./textures/diams.png",
	NULL);
}

void spt_create(game_s *game)
{
	game->bg->back_spt = sfSprite_create();
	game->bg->back_spm3 = sfSprite_create();
	game->bg->back_spm2 = sfSprite_create();
	game->bg->back_spm1 = sfSprite_create();
	game->mn->starter = sfSprite_create();
	game->mn->cutter = sfSprite_create();
	game->gh->dirt = sfSprite_create();
	game->gh->dead = sfSprite_create();
	game->gh->stone = sfSprite_create();
	game->gh->woody = sfSprite_create();
}
