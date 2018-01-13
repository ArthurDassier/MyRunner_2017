/*
** EPITECH PROJECT, 2017
** win_def.c
** File description:
** blabla
*/

#include "my.h"

void win_or_def(game_s *game)
{
	if (game->status == 2)
		defeat_menu(game);
	if (game->status == 3)
		win_menu(game);
}

void defeat_menu(game_s *game)
{
	sfRenderWindow_drawSprite(game->wd.window, game->mn->def, NULL);
	if(sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
		game->status = 0;
		game->check = 1;
	}
}

void win_menu(game_s *game)
{
	sfRenderWindow_drawSprite(game->wd.window, game->mn->vic, NULL);
	if(sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
		game->status = 0;
		game->check = 1;
		game->score = 0;
		game->map = 0;
		sfMusic_stop(game->sd->zikmu);
	}
}
