/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** Duplicate string
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
	int length = my_strlen(src);
	char *dest;

	dest = (char *)malloc(sizeof(char) * (length + 1));
	dest = my_strcpy(dest, src);
	dest[length] = '\0';
	return (dest);
}
