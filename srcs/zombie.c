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

int jump()
{
	static int	jump_up = 0;
	static int	jump_dwn = 0;
	static int	taille = 1100;

	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
		jump_up = 1;
	if (jump_up == 1 && jump_dwn < 8) {
		taille = taille + 25;
		jump_dwn = jump_dwn + 1;
	} else if (jump_up == 1 && jump_dwn < 16) {
		taille = taille - 25;
		jump_dwn = jump_dwn + 1;
	} else {
		jump_up = 0;
		jump_dwn = 0;
	}
	return (taille);
}

sfIntRect position_pixels(int a, int b, int c, int d)
{
	sfIntRect taille;
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
