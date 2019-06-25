/*
** EPITECH PROJECT, 2018
** semicolon.c
** File description:
** Handle semicolon: Execute several commands in the same line
*/

#include "../../include/minishell.h"

void add_index(t_shell *shell)
{
	if (shell->check.pipe != 0)
		++shell->index;
}

void parse_argv_semicolon(t_shell *shell, char **line_parsed)
{
	int list_length = 0;

	if (shell->check.semicolon != 0 || shell->index != 0) {
		if (shell->index != 0)
			++shell->index;
		add_index(shell);
		while (line_parsed[shell->index] != NULL &&
				line_parsed[shell->index][0] != ';' &&
				line_parsed[shell->index][0] != '|') {
			list_length++;
			shell->index++;
		}
		shell->shell_args = malloc(sizeof(char *) * ++list_length);
		for (int j = 0; j < list_length - 1; j++)
			shell->shell_args[j] = my_strdup(line_parsed
					[shell->index - list_length + 1 + j]);
		shell->shell_args[list_length - 1] = NULL;
		check_misplaced_semicolon(shell);
	} else
	return;
}
