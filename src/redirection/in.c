/*
** EPITECH PROJECT, 2018
** in.c
** File description:
** Handle stdin redirections
*/

#include "../../include/minishell.h"

int is_name_for_redirect(t_shell *shell)
{
	int i = 0;

	for (; shell->shell_args[i] != NULL; i++);
	if (my_strcmp(shell->shell_args[i - 1], "<") == 0 ||
			my_strcmp(shell->shell_args[i - 1], ">") == 0) {
		my_putstr("Missing name for redirect.\n");
		return (-1);
	}
	return (0);
}

void in_son(int fd, t_shell *shell, int length_list)
{
	int j = 0;

	dup2(fd, 0);
	shell->command = my_strdup(shell->shell_args[0]);
	parse_environ(shell);
	length_list = my_listlen(shell->path_environ);
	for (j = 0; j < length_list &&
			access(shell->path_environ[j], F_OK); j++);
	execve(shell->path_environ[j], shell->shell_args, shell->env);
	close(fd);
}

void parse_argv_in(t_shell *shell, char **list, char **file_name)
{
	int length = 0;
	int i = 0;

	for (; my_strcmp(list[i], "<") == -1 &&
			my_strcmp(list[i], "<<") == -1; i++)
		length++;
	free_argv(shell);
	shell->shell_args = (char **)malloc(sizeof(char *) * ++length);
	for (int j = 0; j < length - 1; j++)
		shell->shell_args[j] = my_strdup(list[j]);
	shell->shell_args[length - 1] = NULL;
	*file_name = my_strdup(list[length]);
}

void redirect_in(t_shell *shell, char *file_name)
{
	int fd;
	int pid;
	int length_list = 0;
	int i = 0;

	for (; shell->shell_args[i]; i++);
	fd = open(file_name, O_RDONLY);
	if (fd < 0) {
		my_putstr(file_name);
		my_putstr(": No such file or directory.\n");
		return;
	}
	pid = fork();
	if (pid == 0) {
		in_son(fd, shell, length_list);
	}
	wait(&pid);
}

int redirection_in(t_shell *shell, char **list)
{
	char *file_name;

	if (shell->check.in_redirection == 0)
		return (-1);
	if (is_name_for_redirect(shell) != 0)
		return (0);
	parse_argv_in(shell, list, &file_name);
	redirect_in(shell, file_name);
	shell->check.in_redirection = 0;
	return (0);
}
