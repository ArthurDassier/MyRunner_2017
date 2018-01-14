/*
** EPITECH PROJECT, 250017
** zombie.c
** File description:
** blabla
*/

#include "my.h"

void animation(game_s *gm)
{
	if (gm->st.anm == 24)
		gm->st.anm = 0;
	sfSprite_setTextureRect(gm->gh->dead, gm->gh->animation[gm->st.anm]);
	sfSprite_setPosition(gm->gh->dead, gm->gh->zomb_pos);
	gm->st.anm = gm->st.anm + 1;
}

int collision(game_s *gm)
{
	int	i = 0;

	while (gm->gh->pos_map[i].x) {
		if (gm->st.score == -10) {
			reset(gm);
			sfMusic_stop(gm->sd->zikmu);
			break;
		}
		if (gm->gh->pos_map[i].x < gm->gh->zomb_pos.x + 300 &&
			gm->gh->pos_map[i].x + 98 > gm->gh->zomb_pos.x &&
			gm->gh->pos_map[i].y < gm->gh->zomb_pos.y + 440 &&
			98 + gm->gh->pos_map[i].y > gm->gh->zomb_pos.y &&
			gm->st.jump_up == 1) {
				gm->gh->zomb_pos.y = gm->gh->zomb_pos.y - 98;
				return (1);
			}
		if (gm->gh->pos_map[i].x < gm->gh->zomb_pos.x + 300 &&
			gm->gh->pos_map[i].x + 98 > gm->gh->zomb_pos.x &&
			gm->gh->pos_map[i].y < gm->gh->zomb_pos.y + 440 &&
			98 + gm->gh->pos_map[i].y > gm->gh->zomb_pos.y &&
			gm->st.jump_up == 0) {
				reset(gm);
				gm->st.status = 2;
				sfMusic_stop(gm->sd->zikmu);
			}
			++i;
	}
	return (0);
}

int jump(game_s *game)
{
	if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
		game->st.jump_up = 1;
		if (sfSound_getStatus(game->sd->zmb) != sfPlaying)
		sfSound_play(game->sd->zmb);
	}
	game->st.jump = game->st.jump + collision(game);
	if (game->st.jump == 5) {
		game->st.jump = 0;
		game->st.sol = game->st.sol + (98 * 5);
		game->gh->zomb_pos.y = game->gh->zomb_pos.y + (98 * 5);
	}
	if (game->st.jump_up == 1 && game->st.jump_dwn < 8) {
		game->gh->zomb_pos.y = game->gh->zomb_pos.y - 25;
		game->st.jump_dwn = game->st.jump_dwn + 1;
	} else if (game->st.jump_up == 1 && game->st.jump_dwn < 16) {
		game->gh->zomb_pos.y = game->gh->zomb_pos.y + 25;
		game->st.jump_dwn = game->st.jump_dwn + 1;
	} else {
		game->st.jump_up = 0;
		game->st.jump_dwn = 0;
	}
	return (game->st.sol);
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
