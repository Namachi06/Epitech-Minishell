/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** function
*/

#include "../include/minishell.h"

int mysh(t_shell *shell)
{
	if (get_command_and_parse(shell) != 0)
		return (-1);
	if (commands(shell) != 0)
		unknown_command(shell);

	return (0);
}

void enter_command(t_shell *shell)
{
	if (shell->check.semicolon != 0) {
		--shell->check.semicolon;
		shell->check.pipe = 0;
		return;
	}
	shell->index = 0;
	my_putstr("$>");
	if ((shell->get_line = get_next_line(0)) == NULL)
		exit(0);
	is_semicolon(shell);
}

int main(int argc, char *argv[], char *envp[])
{
	t_shell *shell = (t_shell *)malloc(sizeof(t_shell));

	argc = argc;
	argv = argv;
	assign_env(envp, shell);
	shell->check.semicolon = 0;
	shell->index = 0;
	while (41) {
		enter_command(shell);
		mysh(shell);
	}
	free_all(shell);
	return (0);
}
