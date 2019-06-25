/*
** EPITECH PROJECT, 2018
** error.c
** File description:
** Display error possibilities
*/

#include "../include/minishell.h"

void unknown_cd_path(t_shell *shell)
{
	my_putstr(shell->shell_args[1]);
	my_putstr(": Not a directory.\n");
}

int check_setenv_bad_argument(t_shell *shell)
{
	if (shell->argc != 2) {
		my_putstr("setenv: Bad argument.\n");
		return (-1);
	}
	return (0);
}

void unknown_command(t_shell *shell)
{
	if (my_strcmp(shell->command, "exit") == -1) {
		my_putstr(shell->command);
		my_putstr(": Command not found.\n");
	}
}

void check_misplaced_semicolon(t_shell *shell)
{
	for (int i = 0; shell->shell_args[i] != NULL; i++) {
		for (int j = 0; shell->shell_args[i][j] != '\0'; j++)
			if (shell->shell_args[i][j] == ';') {
				shell->check.semicolon = 0;
				shell->index = 0;
				free_argv(shell);
				return;
			}
	}
}
