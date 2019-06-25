/*
** EPITECH PROJECT, 2018
** pipe.c
** File description:
** Handle pipes
*/

#include "../../include/minishell.h"

void son(t_shell *shell, int pipefd[2], char **argv_after_pipe)
{
	int length_list = 0;
	int i = 0;

	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	shell->command = my_strdup(argv_after_pipe[0]);
	parse_environ(shell);
	length_list = my_listlen(shell->path_environ);
	for (i = 0; i < length_list &&
			access(shell->path_environ[i], F_OK); i++);
	execve(shell->path_environ[i], argv_after_pipe, shell->env);
}

void father(t_shell *shell, int pipefd[2])
{
	int length_list = 0;
	int i = 0;

	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	shell->command = my_strdup(shell->shell_args[0]);
	parse_environ(shell);
	length_list = my_listlen(shell->path_environ);
	for (i = 0; i < length_list &&
			access(shell->path_environ[i], F_OK); i++);
	execve(shell->path_environ[i], shell->shell_args, shell->env);
}

void execute_pipe(t_shell *shell, char **argv_after_pipe)
{
	int pid;
	int child;
	int status;
	int pipefd[2];

	pid = fork();
	if (pid > 0)
		waitpid(-1, &status, 0);
	if (pid == 0) {
		pipe(pipefd);
		child = fork();
		if (child > 0)
			father(shell, pipefd);
		else
			son(shell, pipefd, argv_after_pipe);
	}
}

void parse_argv_pipe(t_shell *shell, char **line_split, char ***argv_after_pipe)
{
	int length_argv = 0;
	int length_pipe = 0;

	for (int i = 0; *line_split[i] != '|'; i++)
		length_argv++;
	shell->shell_args = (char **)malloc(sizeof(char *) *
		++length_argv);
	for (int i = 0; i < length_argv - 1; i++)
		shell->shell_args[i] = my_strdup(line_split[i]);
	shell->shell_args[length_argv - 1] = NULL;
	for (int i = length_argv; line_split[i] != NULL &&
			line_split[i][0] != ';'; i++)
		shell->index += ++length_pipe;
	*argv_after_pipe = (char **)malloc(sizeof(char *) * ++length_pipe);
	for (int i = 0; i < length_pipe - 1; i++)
		(*argv_after_pipe)[i] = my_strdup(line_split[length_argv + i]);
	(*argv_after_pipe)[length_pipe - 1] = NULL;
}

int pipes(t_shell *shell, char **line_split)
{
	char **argv_after_pipe;

	if (shell->check.pipe == 0)
		return (-1);
	parse_argv_pipe(shell, line_split, &argv_after_pipe);
	execute_pipe(shell, argv_after_pipe);
	if (shell->check.pipe != 0)
		--shell->check.pipe;
	return (0);
}
