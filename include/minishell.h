/*
** EPITECH PROJECT, 2017
** minishell.h
** File description:
** header
*/

#ifndef MINISHELL_H_
# define MINISHELL_H_
#include "my.h"

typedef struct s_check {
	int semicolon;
	int pipe;
	int out_redirection;
	int in_redirection;
	int double_in_redirection;
	int double_out_redirection;
} t_check;

typedef struct s_shell {
	char *get_line;
	char *command;
	char **env;
	char **shell_args;
	char **path_environ;
	int argc;
	int index;
	t_check check;
} t_shell;

// parsing.c
int parse_line(t_shell *shell);
void parse_argv(t_shell *shell, char **line_parsed);

// commands.c
int commands(t_shell *shell);

// setenv.c
int set_env(t_shell *shell, int *env);

// cd.c
int cd(t_shell *shell, int *env);

// environnement.c
void assign_env(char *envp[], t_shell *shell);
void parse_environ(t_shell *shell);
int execution(t_shell *shell, int *env);

// count.c
void is_semicolon(t_shell *shell);
void check_redirections(t_shell *shell);

// semicolon.c
void parse_argv_semicolon(t_shell *shell, char **line_parsed);

// pipe.c
int pipes(t_shell *shell, char **line_split);

// in.c
int is_name_for_redirect(t_shell *shell);
int redirection_in(t_shell *shell, char **list);

// out.c
int redirection_out(t_shell *shell, char **list);

// utils.c
int get_command_and_parse(t_shell *shell);
char *get_environ(t_shell *shell, char const *environ_name);

// error.c
void unknown_command(t_shell *shell);
void unknown_cd_path(t_shell *shell);
int check_setenv_bad_argument(t_shell *shell);
void check_misplaced_semicolon(t_shell * shell);

// free.c
void free_split(char **split);
void free_shell(t_shell *shell);
void free_all(t_shell *shell);
void free_argv(t_shell *shell);

#endif /* !MINISHELL_H_ */
