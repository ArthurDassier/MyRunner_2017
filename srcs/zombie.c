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
	return(taille);
}

void init_tab(game_s *game)
{
	game->gh->animation[0] = position_pixels(500, 0, 300, 500);
	game->gh->animation[1] = position_pixels(500, 500, 300, 500);
	game->gh->animation[2] = position_pixels(500, 1000, 300, 500);
	game->gh->animation[3] = position_pixels(500, 1500, 300, 500);
	game->gh->animation[4] = position_pixels(500, 2000, 300, 500);
	game->gh->animation[5] = position_pixels(500, 2500, 300, 500);
	game->gh->animation[6] = position_pixels(500, 3000, 300, 500);
	game->gh->animation[7] = position_pixels(500, 3500, 300, 500);
	game->gh->animation[8] = position_pixels(500, 4000, 300, 500);
	game->gh->animation[9] = position_pixels(500, 4500, 300, 500);
	game->gh->animation[10] = position_pixels(500, 5000, 300, 500);
	game->gh->animation[11] = position_pixels(500, 5500, 300, 500);
	game->gh->animation[12] = position_pixels(500, 6000, 300, 500);
	game->gh->animation[13] = position_pixels(500, 6500, 300, 500);
	game->gh->animation[14] = position_pixels(500, 7000, 300, 500);
	game->gh->animation[15] = position_pixels(500, 7500, 300, 500);
	game->gh->animation[16] = position_pixels(500, 8000, 300, 500);
	game->gh->animation[17] = position_pixels(500, 8500, 300, 500);
	game->gh->animation[18] = position_pixels(500, 9000, 300, 500);
	game->gh->animation[19] = position_pixels(500, 9500, 300, 500);
	game->gh->animation[20] = position_pixels(500, 10000, 300, 500);
	game->gh->animation[21] = position_pixels(500, 10500, 300, 500);
	game->gh->animation[22] = position_pixels(500, 11000, 300, 500);
	game->gh->animation[23] = position_pixels(500, 11500, 300, 500);
}
