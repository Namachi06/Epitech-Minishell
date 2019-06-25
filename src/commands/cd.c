/*
** EPITECH PROJECT, 2018
** cd.c
** File description:
** CD Command
*/

#include "../../include/minishell.h"

int check_chdir(t_shell *shell)
{
	if (chdir(shell->shell_args[1]) == 0)
		return (0);
	unknown_cd_path(shell);
	return (-1);
}

int do_cd(t_shell *shell)
{
	char *home;

	if (shell->argc == 2) {
		if (my_strcmp(shell->shell_args[1], "~") == 0) {
			home = get_environ(shell, "HOME");
			chdir(home);
			free(home);
			return (0);
		} else
			check_chdir(shell);
	} else if (shell->argc == 1) {
		home = get_environ(shell, "HOME");
		chdir(home);
		free(home);
		return (0);
	}
	return (-1);
}

int cd(t_shell *shell, int *env)
{
	*env = 1;
	if (shell->argc > 2) {
		my_putstr("cd: Too many arguments.\n");
		return (-1);
	}
	do_cd(shell);
	return (0);
}
