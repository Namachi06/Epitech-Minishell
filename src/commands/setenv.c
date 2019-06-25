/*
** EPITECH PROJECT, 2018
** setenv.c
** File description:
** Command setenv
*/

#include "../../include/minishell.h"

char **setenv_realloc(t_shell *shell, int *i, int *length_list, int *length_env)
{
	int length_line = 0;
	char **new_env;

	*length_env = my_strlen(shell->shell_args[1]);
	new_env = (char **)malloc(sizeof(char *) * (*length_list += 2));
	for (*i = 0; *i < *length_list - 2; (*i)++) {
		length_line = my_strlen(shell->env[*i]);
		new_env[*i] = (char *)malloc(sizeof(char) * length_line + 1);
		my_strncpy(new_env[*i], shell->env[*i], length_line + 1);
	}
	return (new_env);
}

int set_env(t_shell *shell, int *env)
{
	*env = 1;
	int i = 0;
	int length_list = my_listlen(shell->env);
	int length_env;
	char **new_env;

	if (check_setenv_bad_argument(shell) != 0)
		return (-1);
	new_env = setenv_realloc(shell, &i, &length_list, &length_env);
	new_env[i] = (char *)malloc(sizeof(char) * length_env + 1);
	my_strncpy(new_env[i], shell->shell_args[1], length_env + 1);
	new_env[length_list - 1] = NULL;
	shell->env = new_env;
	return (0);
}
