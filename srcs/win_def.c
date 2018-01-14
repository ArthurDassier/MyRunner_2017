/*
** EPITECH PROJECT, 2017
** win_def.c
** File description:
** blabla
*/

#include "my.h"

void win_or_def(game_s *game)
{
	if (game->st.status == 2)
		defeat_menu(game);
	if (game->st.status == 3)
		win_menu(game);
}

void defeat_menu(game_s *game)
{
	sfRenderWindow_drawSprite(game->wd.window, game->mn->def, NULL);
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
		reset(game);
	}
}

void win_menu(game_s *game)
{
	sfRenderWindow_drawSprite(game->wd.window, game->mn->vic, NULL);
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
		reset(game);
		sfMusic_stop(game->sd->zikmu);
		game->st.score = -10;
	}
}

void reset(game_s *game)
{
	game->st.status = 0;
	game->st.check = 1;
	game->st.score = 0;
	game->st.map = 0;
	game->gh->map_pos.y = 1100;
	game->st.jump = 0;
	game->st.sol = 1100;
	game->gh->zomb_pos.y = 458;
	game->st.jump_up = 0;
	game->st.jump_dwn = 0;
}
