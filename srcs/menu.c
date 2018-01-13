/*
** EPITECH PROJECT, 2017
** menu.c
** File description:
** blabla
*/

#include "my.h"

void display_code(game_s *gm, char *buffer)
{
	if (gm->st.status == 0)
		display_start(gm);
	if (gm->st.status == 1) {
		animation(gm);
		display_map(gm, buffer);
		sfRenderWindow_drawSprite(gm->wd.window, gm->gh->dead, NULL);
	} else
		win_or_def(gm);
}

int key_enter(game_s *game)
{
	static int	status = 0;

	if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
		status = 1;
		if (sfSound_getStatus(game->sd->epe) != sfPlaying)
			sfSound_play(game->sd->epe);
	}
	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
		status = 0;
		if (sfSound_getStatus(game->sd->epe) != sfPlaying)
			sfSound_play(game->sd->epe);
	}
	return (status);
}

void return_enter(game_s *game, int status)
{
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue &&
		status == 0 && game->st.check == 0) {
		sfMusic_play(game->sd->zikmu);
		sfMusic_setVolume(game->sd->zikmu, 25);
		game->st.status = 1;
	}
	if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue && status == 1)
		sfRenderWindow_close(game->wd.window);
	game->st.check = 0;
}

void display_start(game_s *game)
{
	static int	status = 0;

	sfRenderWindow_drawSprite(game->wd.window, game->mn->starter, NULL);
	sfRenderWindow_drawSprite(game->wd.window, game->mn->cutter, NULL);
	status = key_enter(game);
	if (status == 0) {
		game->mn->swd_pos.x = 390;
		game->mn->swd_pos.y = 490;
	} else {
		game->mn->swd_pos.x = 600;
		game->mn->swd_pos.y = 650;
	}
	sfSprite_setPosition(game->mn->cutter, game->mn->swd_pos);
	return_enter(game, status);
}
