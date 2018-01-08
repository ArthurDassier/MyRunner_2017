/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** blabla
*/

#include "my.h"

void display_code(game_s *game, char *buffer)
{
	static int u = 0;

	if (u == 0)
		u = display_start(game);
	else {
		animation(game);
		display_map(game, buffer);
		sfRenderWindow_drawSprite(game->wd.window, game->gh->dead, NULL);
	}
}

int key_enter()
{
	static int	status = 0;

	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
		status = 1;
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
		status = 0;
	return (status);
}

int return_enter(game_s *game, int status)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && status == 0)
		return (1);
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && status == 1)
		sfRenderWindow_close(game->wd.window);
	return (0);
}

int display_start(game_s *game)
{
	static int	status = 0;

	sfRenderWindow_drawSprite(game->wd.window, game->mn->starter, NULL);
	sfRenderWindow_drawSprite(game->wd.window, game->mn->cutter, NULL);
	status = key_enter();
	if (status == 0) {
		game->mn->swd_pos.x = 390;
		game->mn->swd_pos.y = 490;
	} else {
		game->mn->swd_pos.x = 600;
		game->mn->swd_pos.y = 650;
	}
	sfSprite_setPosition(game->mn->cutter, game->mn->swd_pos);
	return (return_enter(game, status));
}
