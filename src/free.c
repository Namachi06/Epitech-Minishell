/*
** EPITECH PROJECT, 2018
** free.c
** File description:
** Free t'as tout compris
*/

#include "../include/minishell.h"

void free_split(char **split)
{
	for (int i = 0; split[i] != NULL; i++)
		free(split[i]);
	free(split);
}

void free_all(t_shell *shell)
{
	free_shell(shell);
	free(shell);
}

void free_argv(t_shell *shell)
{
	if (shell->shell_args == NULL)
		return;
	for (int i = 0; shell->shell_args[i] != NULL; i++)
		free(shell->shell_args[i]);
	free(shell->shell_args);
}

void free_shell(t_shell *shell)
{
	free(shell->command);
	free(shell->get_line);
	for (int i = 0; shell->path_environ[i] != NULL; i++)
		free(shell->path_environ[i]);
	free(shell->path_environ);
	for (int i = 0; shell->env[i] != NULL; i++)
		free(shell->env[i]);
	free(shell->env);
	free_argv(shell);
}
