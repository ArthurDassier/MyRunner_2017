/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"

void help()
{
	my_printf("ALPHA (v:1.6 my_runner) IN DEVELOPEMENT\n");
}

void play(game_s game, char *argv)
{
	int fd = open(argv, O_RDONLY);
	char *buffer = malloc(sizeof(int) * 400000);

	read(fd, buffer, sizeof(int) * 400000);
	general_init(&game);
	while (sfRenderWindow_isOpen(game.wd.window)) {
		animation(&game);
		display_map(game, buffer);
		sfRenderWindow_drawSprite(game.wd.window, game.gh->dead, NULL);
		sfRenderWindow_display(game.wd.window);
		analyse_event(game);
		sfSleep(game.wd.time_s);
	}
}

int main(int argc, char *argv[])
{
	game_s	game;

	game.gh = malloc(sizeof(graphs));
	game.bg = malloc(sizeof(background));
	if (argc != 2)
		return (84);
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
		help();
		return (0);
	} else
		play(game, argv[1]);
	return (0);
}
