/*
** EPITECH PROJECT, 2017
** my_split
** File description:
** 	Split the string with separator
*/
#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

void init_struct(t_split *split)
{
	split->found_string = NULL;
	split->count_number_of_lines = 0;
	split->index_list = 0;
	split->last_separator_index = 0;
	split->length = 0;
	split->list = NULL;
}

void do_split(t_split *split, char *str, char separator)
{
	for (int i = 0;; i++) {
		if (str[i] == separator || str[i] == '\0' || str[i] == '\n') {
			split->length = i - split->last_separator_index;
			split->found_string = malloc(sizeof(char) *
				split->length + 1);
			my_strncpy(split->found_string, &str
				[split->last_separator_index],
				split->length);
			split->found_string[split->length] = '\0';
			split->list[split->index_list++] =
				split->found_string;
			split->last_separator_index = i + 1;
			if (str[i] == '\0') {
				break;
			}
		}
	}
}

void count(t_split *split, char *str, char separator)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (i == 0) {
			split->count_number_of_lines = 2;
		}
		if (str[i] == separator) {
			split->count_number_of_lines++;
		}
	}
}

char **my_split(char *str, char separator)
{
	t_split *split;
	char **list;

	if (str == NULL)
		return (NULL);
	split = malloc(sizeof(t_split));
	init_struct(split);
	count(split, str, separator);
	if (split->count_number_of_lines > 0) {
		split->list = malloc(sizeof(char *) *
			split->count_number_of_lines);
	}
	do_split(split, str, separator);
	split->list[split->count_number_of_lines - 1] = NULL;
	list = split->list;
	return (list);
}
