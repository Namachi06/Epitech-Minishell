/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** 	Put characters in a string
*/

#include "../../include/my.h"

int my_putstr(char const *str)
{
	int iteration = 0;

	while (str[iteration] != '\0') {
		my_putchar(str[iteration]);
		iteration += 1;
	}
	return (0);
}
