/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"

void help()
{
	my_printf("ALPHA (v:0.2 my_runner) IN DEVELOPEMENT\n");
}

void play(game_s game, graphs *graph, char str[8])
{
	general_init(&game, graph);
	while (sfRenderWindow_isOpen(game.window)) {
		sfRenderWindow_drawSprite(game.window, graph->back_grd, NULL);
		sfSprite_setTexture(graph->dirt, graph->grass, sfTrue);
		sfSprite_setTexture(graph->stone, graph->cobble, sfTrue);
		read_map(&game, graph, str);
		sfRenderWindow_display(game.window);
		analyse_event(game);
		sfSleep(game.time_s);
	}
}

int main(int argc, char *argv[])
{
	game_s	game;
	graphs	*graph = malloc(sizeof(graphs));

	char str[8] = "112211";
	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
		help();
		return(0);
	}
	else
		play(game, graph, str);
	return (0);
}
