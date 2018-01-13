/*
** EPITECH PROJECT, 2017
** my_return_str.c
** File description:
** putnbr
*/

#include <stdlib.h>

char *my_return_str(int i, char *str)
{
	char const	digit[] = "0123456789";
	char		*tmp = str;
	int		shifter = i;

	++tmp;
	++tmp;
	++tmp;
	++tmp;
	++tmp;
	++tmp;
	++tmp;
	++tmp;
	while (shifter) {
		++tmp;
		shifter = shifter / 10;
		*tmp = '\0';
	}
	while (i) {
		*--tmp = digit[i % 10];
		i = i / 10;
	}
	return (str);
}
