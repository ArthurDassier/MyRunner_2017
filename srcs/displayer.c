/*
** EPITECH PROJECT, 2017
** displayer.c
** File description:
** blabla
*/

#include "my.h"

void number_map(game_s *gm, char *buffer, int i, int count)
{
	gm->gh->pos_map[count].x = gm->gh->map_pos.x;
	gm->gh->pos_map[count].y = gm->gh->map_pos.y;
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

void my_score(game_s *game)
{
	char	str[20] = "Score : ";

	game->wd.font = sfFont_createFromFile("./fonts/arial.ttf");
	game->wd.text = sfText_create();
	sfText_setString(game->wd.text, my_return_str(game->st.score, str));
	sfText_setFont(game->wd.text, game->wd.font);
	sfText_setCharacterSize(game->wd.text, 50);
	sfRenderWindow_drawText(game->wd.window, game->wd.text, NULL);
}
