/*
** EPITECH PROJECT, 250017
** zombie.c
** File description:
** blabla
*/

#include "my.h"

void animation(game_s *game)
{
	if (game->anm == 24)
		game->anm = 0;
	sfSprite_setTextureRect(game->gh->dead, game->gh->animation[game->anm]);
	sfSprite_setPosition(game->gh->dead, game->gh->zomb_pos);
	game->anm = game->anm + 1;
}

int collision(game_s *game, int jump_up)
{
	int	i = 0;

	while (game->gh->pos_map[i].x) {
		if (game->gh->pos_map[i].x < game->gh->zomb_pos.x + 300 &&
			game->gh->pos_map[i].x + 98 > game->gh->zomb_pos.x &&
			game->gh->pos_map[i].y < game->gh->zomb_pos.y + 440 &&
			98 + game->gh->pos_map[i].y > game->gh->zomb_pos.y &&
			jump_up == 1) {
				game->gh->zomb_pos.y = game->gh->zomb_pos.y - 98;
				return (1);
			}
		if (game->gh->pos_map[i].x < game->gh->zomb_pos.x + 300 &&
			game->gh->pos_map[i].x + 98 > game->gh->zomb_pos.x &&
			game->gh->pos_map[i].y < game->gh->zomb_pos.y + 440 &&
			98 + game->gh->pos_map[i].y > game->gh->zomb_pos.y &&
			jump_up == 0) {
				game->status = 2;
				game->map = 0;
				game->gh->zomb_pos.y = 460;
				sfMusic_stop(game->sd->zikmu);
			}
			++i;
	}
	return (0);
}

int jump(game_s *game)
{
	static int	jump_up = 0;
	static int	jump_dwn = 0;
	static int	ground = 1100;
	static int	status = 0;

	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
		jump_up = 1;
		if (sfSound_getStatus(game->sd->zmb) != sfPlaying)
		sfSound_play(game->sd->zmb);
	}
	status = status + collision(game, jump_up);
	if (status == 5) {
		status = 0;
		ground = ground + (98 * 5);
		game->gh->zomb_pos.y = game->gh->zomb_pos.y + (98 * 5);
	}
	if (jump_up == 1 && jump_dwn < 8) {
		game->gh->zomb_pos.y = game->gh->zomb_pos.y - 25;
		jump_dwn = jump_dwn + 1;
	} else if (jump_up == 1 && jump_dwn < 16) {
		game->gh->zomb_pos.y = game->gh->zomb_pos.y + 25;
		jump_dwn = jump_dwn + 1;
	} else {
		jump_up = 0;
		jump_dwn = 0;
	}
	return (ground);
}

sfIntRect position_pixels(int a, int b, int c, int d)
{
	sfIntRect	taille;

	taille.height = a;
	taille.left = b;
	taille.top = c;
	taille.width = d;
	return (taille);
}

void init_tab(game_s *game)
{
	int	stand = 0;
	int	i = 0;

	while (i != 24) {
		game->gh->animation[i] = position_pixels(500, stand, 300, 500);
		stand = stand + 500;
		++i;
	}
}
