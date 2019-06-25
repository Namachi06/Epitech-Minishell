/*
** EPITECH PROJECT, 2017
** parsing.c
** File description:
** function
*/

#include "../include/minishell.h"

void parse_argv(t_shell *shell, char **line_parsed)
{
	int list_length = my_listlen(line_parsed);

	shell->shell_args = (char **)malloc(sizeof(char *) * ++list_length);
	for (int i = 0; i < list_length - 1; i++)
		shell->shell_args[i] = my_strdup(line_parsed[i]);
	shell->shell_args[list_length - 1] = NULL;
}

int check_parsing(t_shell *shell)
{
	char **line_parsed = my_split(shell->get_line, ' ');

	parse_argv(shell, line_parsed);
	check_redirections(shell);
	parse_argv_semicolon(shell, line_parsed);
	if (pipes(shell, line_parsed) == 0)
		return (-1);
	if (redirection_out(shell, line_parsed) == 0)
		return (-1);
	if (redirection_in(shell, line_parsed) == 0)
		return (-1);
	free_split(line_parsed);
	return (0);
}

int parse_line(t_shell *shell)
{
	if (shell->get_line[0] == '\0')
		return (-1);
	if (check_parsing(shell) != 0)
		return(-1);
	shell->command = my_strdup(shell->shell_args[0]);
	shell->argc = my_listlen(shell->shell_args);
	return (0);
}
