/*
** EPITECH PROJECT, 2017
** environnement.c
** File description:
** function
*/

#include "../include/minishell.h"

void assign_env(char *envp[], t_shell *shell)
{
	int length_env = my_listlen(envp);

	shell->env = (char **)malloc(sizeof(char *) * ++length_env);
	for (int i = 0; i < length_env - 1; i++)
		shell->env[i] = my_strdup(envp[i]);
	shell->env[length_env - 1] = NULL;
}

void parse_environ(t_shell *shell)
{
	char *get_env = get_environ(shell, "PATH");
	char **environ = my_split(get_env, ':');
	int length_list = my_listlen(environ);
	int length_command = my_strlen(shell->command);
	int length_line;

	shell->path_environ = (char **)malloc(sizeof(char *) * length_list + 1);
	for (int i = 0; i < length_list; i++) {
		length_line = my_strlen(environ[i]);
		shell->path_environ[i] = (char *)malloc(sizeof(char) *
			length_line + length_command + 2);
		my_strncpy(shell->path_environ[i], environ[i], length_line);
		shell->path_environ[i][length_line] = '/';
		my_strncpy(&shell->path_environ[i][length_line + 1],
			shell->command, length_command + 1);
	}
	shell->path_environ[length_list - 1] = NULL;
	free_split(environ);
}

int execution(t_shell *shell, int *env)
{
	pid_t pid;
	int check = 0;
	int length_list = my_listlen(shell->path_environ);
	int i;

	for (i = 0; i < length_list && ((check = access(shell->path_environ[i],
			F_OK)) != 0); i++);
	if (check != 0)
		return (-1);
	*env = 1;
	pid = fork();
	if (pid == 0)
		execve(shell->path_environ[i], shell->shell_args, shell->env);
	wait(&pid);
	return (0);
}
