/*
** EPITECH PROJECT, 2017
** commands.c
** File description:
** function
*/

#include "../../include/minishell.h"

int exit_command(t_shell *shell, int *env)
{
	*env = *env;
	free_all(shell);
	exit(0);
}

int commands(t_shell *shell)
{
	int env = 0;
	int check = 0;
	int (*ptr[3])(t_shell *, int *) = { set_env, cd, exit_command };
	char const *commands[] = { "setenv", "cd", "exit" };

	for (int i = 0; i < 3; i++) {
		if (my_strcmp(commands[i], shell->command) == 0) {
			ptr[i](shell, &env);
			break;
		}
	}
	if (env == 0)
		check = execution(shell, &env);
	if (check != 0 || env == 0)
		return (-1);
	return (0);
}
