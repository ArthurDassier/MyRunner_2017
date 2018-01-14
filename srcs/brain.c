/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"

void help(void)
{
	my_printf("Keep running and you will earn points as long as\n");
	my_printf("you don't take a block in your face !\nSPACE for jump\n");
	my_printf("glhf\n");
}

void play(game_s game, char *argv)
{
	int	fd = open(argv, O_RDONLY);
	char	*buffer = malloc(sizeof(char) * 1024);
	char	str[0];
	int	check = 1;
	int	i = 0;

	while ((check = read(fd, str, 1) > 0)) {
		buffer[i] = str[0];
		buffer = my_realloc(buffer);
		++i;
	}
	buffer[i] = '\0';
	general_init(&game);
	while (sfRenderWindow_isOpen(game.wd.window)) {
		display_code(&game, buffer);
		sfRenderWindow_display(game.wd.window);
		analyse_event(game);
		sfSleep(game.wd.time_s);
	}
	destroyer(&game, buffer);
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
