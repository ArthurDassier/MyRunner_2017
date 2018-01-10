/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** blabla
*/

#include "my.h"

void display_map(game_s *game, char *str)
{
	sfRenderWindow_drawSprite(game->wd.window, game->bg->back_spt, NULL);
	sfSprite_setTexture(game->gh->dirt, game->gh->grass, sfTrue);
	sfSprite_setTexture(game->gh->stone, game->gh->cobble, sfTrue);
	sfSprite_setTexture(game->gh->woody, game->gh->wood, sfTrue);
	sfSprite_setTexture(game->bg->back_spm3, game->bg->back_mt3, sfTrue);
	sfSprite_setTexture(game->bg->back_spm2, game->bg->back_mt2, sfTrue);
	sfSprite_setTexture(game->bg->back_spm1, game->bg->back_mt1, sfTrue);
	draw_background(game);
	read_map(game, str);
}

void draw_background(game_s *gm)
{
	gm->bg->m3_pos.x = gm->bg->m3_pos.x - 1;
	gm->bg->m2_pos.x = gm->bg->m2_pos.x - 2;
	gm->bg->m1_pos.x = gm->bg->m1_pos.x - 4;
	gm->bg->m3_pos.y = 50;
	gm->bg->m2_pos.y = 200;
	gm->bg->m1_pos.y = 600;
	sfRenderWindow_drawSprite(gm->wd.window, gm->bg->back_spm3, NULL);
	sfRenderWindow_drawSprite(gm->wd.window, gm->bg->back_spm2, NULL);
	sfRenderWindow_drawSprite(gm->wd.window, gm->bg->back_spm1, NULL);
	sfSprite_setPosition(gm->bg->back_spm3, gm->bg->m3_pos);
	sfSprite_setPosition(gm->bg->back_spm2, gm->bg->m2_pos);
	sfSprite_setPosition(gm->bg->back_spm1, gm->bg->m1_pos);
}
void read_map(game_s *game, char *buffer)
{
	int		i = 0;
	static int	j = 0;

	game->gh->map_pos.x = 0 - j;
	game->gh->map_pos.y = jump(void);
	while (i != my_strlen(buffer)) {
		if (buffer[i] == '1' || buffer[i] == '2' || buffer[i] == '3') {
			number_map(game, buffer, i);
		} else if (buffer[i] == '\n') {
			game->gh->map_pos.x = 0 - j;
			game->gh->map_pos.y = game->gh->map_pos.y - 98;
		} else
			game->gh->map_pos.x = game->gh->map_pos.x + 98;
		++i;
	}
	j = j + 8;
}
