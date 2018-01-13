/*
** EPITECH PROJECT, 2017
** destroy.c
** File description:
** blabla
*/

#include "my.h"

void destroyer(game_s *game)
{
	destroy_sprt(game);
	destroy_text(game);
	destroy_snds(game);
	sfRenderWindow_destroy(game->wd.window);
	free(game->gh);
	free(game->bg);
	free(game->sd);
	free(game->mn);
}

void destroy_text(game_s *game)
{
	sfTexture_destroy(game->bg->back_txt);
	sfTexture_destroy(game->bg->back_mt3);
	sfTexture_destroy(game->bg->back_mt2);
	sfTexture_destroy(game->bg->back_mt1);
	sfTexture_destroy(game->mn->menu_start);
	sfTexture_destroy(game->mn->sword);
	sfTexture_destroy(game->mn->defeat);
	sfTexture_destroy(game->mn->win);
	sfTexture_destroy(game->gh->grass);
	sfTexture_destroy(game->gh->cobble);
	sfTexture_destroy(game->gh->wood);
	sfTexture_destroy(game->gh->zombie);
}

void destroy_sprt(game_s *game)
{
	sfSprite_destroy(game->bg->back_spt);
	sfSprite_destroy(game->bg->back_spm3);
	sfSprite_destroy(game->bg->back_spm2);
	sfSprite_destroy(game->bg->back_spm1);
	sfSprite_destroy(game->gh->dead);
	sfSprite_destroy(game->gh->dirt);
	sfSprite_destroy(game->gh->stone);
	sfSprite_destroy(game->gh->woody);
	sfSprite_destroy(game->mn->starter);
	sfSprite_destroy(game->mn->cutter);
	sfSprite_destroy(game->mn->def);
	sfSprite_destroy(game->mn->vic);
}

void destroy_snds(game_s *game)
{
	sfSound_destroy(game->sd->zmb);
	sfSound_destroy(game->sd->epe);
	sfSoundBuffer_destroy(game->sd->zombos);
	sfSoundBuffer_destroy(game->sd->epee);
	sfMusic_destroy(game->sd->zikmu);
}
