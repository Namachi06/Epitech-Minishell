/*
** EPITECH PROJECT, 2017
** utils.c
** File description:
** Untils fonctions
*/

#include "../include/minishell.h"

int get_command_and_parse(t_shell *shell)
{
	if (parse_line(shell) != 0) {
		if (shell->check.semicolon == 0)
			free(shell->get_line);
		return (-1);
	}
		parse_environ(shell);
	return (0);
}

char *get_environ(t_shell *shell, char const *environ_name)
{
	char **get_environ_name = NULL;
	char *path = NULL;

	for (int i = 0; shell->env[i] != NULL; i++) {
		get_environ_name = my_split(shell->env[i], '=');
		if (get_environ_name != NULL) {
			if (my_strcmp(get_environ_name[0], environ_name) == 0)
				path = get_environ_name[1];
		}
	}
	return (path);
}
