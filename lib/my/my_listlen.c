/*
** EPITECH PROJECT, 2017
** my_listlen.c
** File description:
** function
*/

#include <stdio.h>

int my_listlen(char **list)
{
	int count = 0;

	if (list == NULL)
		return (-1);
	for (int i = 0; list[i] && list[i][0] != ';'; i++)
		count++;
	return (count);
}
