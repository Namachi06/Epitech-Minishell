/*
** EPITECH PROJECT, 2018
** out.c
** File description:
** Handle out redirections
*/

#include "../../include/minishell.h"

void parse_argv_out(t_shell *shell, char **list, char **file_name)
{
	int length = 0;
	int i = 0;

	for (; my_strcmp(list[i], ">") == -1 && my_strcmp(list[i], ">>") == -1;
			i++)
		length++;
	free_argv(shell);
	shell->shell_args = (char **)malloc(sizeof(char *) * ++length);
	for (int j = 0; j < length - 1; j++)
		shell->shell_args[j] = my_strdup(list[j]);
	shell->shell_args[length - 1] = NULL;
	*file_name = my_strdup(list[length]);
}

void  child_out_redirection(t_shell *shell, int length_list, char *file_name)
{
	int j = 0;
	int fd;

	if (shell->check.double_out_redirection != 0)
		fd = open(file_name, O_RDWR | O_APPEND | O_CREAT, 0775);
	else
		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0775);
	dup2(fd, 1);
	shell->command = my_strdup(shell->shell_args[0]);
	parse_environ(shell);
	length_list = my_listlen(shell->path_environ);
	for (j = 0; j < length_list &&
			access(shell->path_environ[j], F_OK); j++);
	execve(shell->path_environ[j], shell->shell_args, shell->env);
	close(fd);
}

void redirect(t_shell *shell, char *file_name)
{
	int pid;
	int length_list = 0;
	int i = 0;

	for (; shell->shell_args[i]; i++);
	pid = fork();
	if (pid == 0)
		child_out_redirection(shell, length_list, file_name);
	wait(&pid);
}

int redirection_out(t_shell *shell, char **list)
{
	char *file_name;

	if (shell->check.out_redirection == 0)
		return (-1);
	if (is_name_for_redirect(shell) != 0)
		return (0);
	parse_argv_out(shell, list, &file_name);
	redirect(shell, file_name);
	shell->check.out_redirection = 0;
	shell->check.double_out_redirection = 0;
	return (0);
}
