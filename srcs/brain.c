/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"

void help(void)
{
	my_printf("Keep running and you will earn points !\n");
	my_printf("glhf\n");
}

void play(game_s game, char *argv)
{
	int	fd = open(argv, O_RDONLY);
	char	*buffer = malloc(sizeof(char) * 40000);

	read(fd, buffer, sizeof(char) * 40000);
	general_init(&game);
	while (sfRenderWindow_isOpen(game.wd.window)) {
		display_code(&game, buffer);
		sfRenderWindow_display(game.wd.window);
		analyse_event(game);
		sfSleep(game.wd.time_s);
	}
	destroyer(&game);
	free(buffer);
}

int main(int argc, char *argv[])
{
	game_s	game;

	game.gh = malloc(sizeof(graphs));
	game.bg = malloc(sizeof(background));
	game.sd = malloc(sizeof(sounds));
	game.mn = malloc(sizeof(menus));
	if (argc != 2) {
		my_puterror("You must give a map as argument\n");
		return (84);
	}
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
		help();
		return (0);
	} else
		play(game, argv[1]);
	return (0);
}
