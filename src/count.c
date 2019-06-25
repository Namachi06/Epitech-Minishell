/*
** EPITECH PROJECT, 2018
** count.c
** File description:
** Count all redirections
*/

#include "../include/minishell.h"

void is_semicolon(t_shell *shell)
{
	for (int i = 0; shell->get_line[i] != '\0'; i++)
		if (shell->get_line[i] == ';')
			shell->check.semicolon++;
}

void is_pipe(t_shell *shell)
{
	shell->check.pipe = 0;
	for (int i = 0; shell->shell_args[i] != NULL; i++)
		if (shell->shell_args[i][0] == '|')
			shell->check.pipe++;
}

void is_in_out_redirection(t_shell *shell)
{
	shell->check.out_redirection = 0;
	shell->check.in_redirection = 0;
	for (int i = 0; shell->shell_args[i] != NULL; i++)
		if (shell->shell_args[i][0] == '>')
			shell->check.out_redirection++;
		else if (shell->shell_args[i][0] == '<')
			shell->check.in_redirection++;
}

void is_double_in_out_redirection(t_shell *shell)
{
	shell->check.double_out_redirection = 0;
	shell->check.double_in_redirection = 0;
	for (int i = 0; shell->shell_args[i] != NULL; i++)
		if (my_strcmp(shell->shell_args[i], ">>") == 0)
			shell->check.double_out_redirection++;
		else if (my_strcmp(shell->shell_args[i], "<<") == 0)
			shell->check.double_out_redirection++;
}

void check_redirections(t_shell *shell)
{
	is_pipe(shell);
	is_in_out_redirection(shell);
	is_double_in_out_redirection(shell);
}
