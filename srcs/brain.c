/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "my.h"

void help()
{
	my_printf("Help :\nMouse click on the birds to earn points !\n");
	my_printf("The game exit when a bird reach the right side of the ");
	my_printf("screen,\nthen you'll see your score on the shell.\n");
	my_printf("Have fun playing My Hunter ! :)\n");

}

void play(game_s game)
{
	sfEvent	event;
	game.video_mode.width = 1920;
	game.video_mode.height = 1080;
	game.video_mode.bitsPerPixel = 8;
	game.window = sfRenderWindow_create(game.video_mode, "MyWindow",
	sfDefaultStyle, NULL);
	while (sfRenderWindow_isOpen(game.window)) {
		while (sfRenderWindow_pollEvent(game.window, &event)) {
			if (event.type == sfEvtClosed) {
				my_printf("pfff, looser.\n");
				sfRenderWindow_close(game.window);
			}
		}
	}
}

int main(int argc, char *argv[])
{
	game_s	game;

	if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
		help();
		return(0);
	}
	else
		play(game);
	return (0);
}
