/*
** EPITECH PROJECT, 2017
** displayer.c
** File description:
** blabla
*/

#include "my.h"

void number_map(game_s *gm, char *buffer, int i)
{
	if (buffer[i] == '1') {
		sfRenderWindow_drawSprite(gm->wd.window, gm->gh->dirt, NULL);
		sfSprite_setPosition(gm->gh->dirt, gm->gh->map_pos);
		gm->gh->map_pos.x = gm->gh->map_pos.x + 98;
	} else if (buffer[i] == '2') {
		sfRenderWindow_drawSprite(gm->wd.window, gm->gh->stone, NULL);
		sfSprite_setPosition(gm->gh->stone, gm->gh->map_pos);
		gm->gh->map_pos.x = gm->gh->map_pos.x + 98;
	} else if (buffer[i] == '3') {
		sfRenderWindow_drawSprite(gm->wd.window, gm->gh->woody, NULL);
		sfSprite_setPosition(gm->gh->woody, gm->gh->map_pos);
		gm->gh->map_pos.x = gm->gh->map_pos.x + 98;
	}
}
