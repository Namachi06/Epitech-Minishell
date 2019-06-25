/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** cat
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
	int i;
	int dest_length = my_strlen(dest);
	int src_length = my_strlen(src);

	for (i = 0; i < src_length; i++) {
		dest[dest_length + i] = src[i];
	}
	dest[dest_length + i] = '\0';
	return (dest);
}
