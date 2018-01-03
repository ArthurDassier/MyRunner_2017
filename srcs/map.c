/*
** EPITECH PROJECT, 2017
** map.c
** File description:
** blabla
*/

#include "my.h"

void display_map(game_s game, char *str)
{
	sfRenderWindow_drawSprite(game.wd.window, game.bg->back_spt, NULL);
	sfSprite_setTexture(game.gh->dirt, game.gh->grass, sfTrue);
	sfSprite_setTexture(game.gh->stone, game.gh->cobble, sfTrue);
	sfSprite_setTexture(game.gh->woody, game.gh->wood, sfTrue);
	read_map(&game, str);
}

void read_map(game_s *game, char *buffer)
{
	int	i = 0;
	static int j = 0;

	game->gh->map_pos.x = 0 - j;
	game->gh->map_pos.y = 1100;
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

void check_collision(game_s *game)
{
	//printf("%f\n", game->gh->map_pos.y);
	//printf("%d\n", game->gh->map_pos.y + 98 > game->gh->zomb_pos.y + 446 &&
	//game->gh->map_pos.y < game->gh->zomb_pos.y + 446);
	//if (game->gh->map_pos.y + 98 > game->gh->zomb_pos.y + 446 &&
	//game->gh->map_pos.y < game->gh->zomb_pos.y + 446) {
		//	sfRenderWindow_close(game->wd.window);
	//}
}
