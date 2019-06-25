/*
** EPITECH PROJECT, 2017
** my_realloc
** File description:
** 	memory reallocation
*/

#include <unistd.h>
#include <stdlib.h>

char *my_realloc(char *string, int length) {
	char *new_memory;

	new_memory = (char *)malloc(sizeof(char) * length + 1);
	if (string == NULL) {
		return (new_memory);
	}
	for (int i = 0; string[i] != '\0'; i++) {
		new_memory[i] = string[i];
	}
	free(string);
	return (new_memory);
}
