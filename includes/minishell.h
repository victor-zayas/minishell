/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:41:08 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/04/25 11:23:26 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <termios.h>
# include <sys/termios.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_it
{
	int	i1;
	int	i2;
	int	i3;
	int	i4;
	int	i5;
	int	i6;
	int	i7;
}	t_it;

typedef struct s_env
{
	char	*oldpwd;
	char	*pwd;
	char	**env;
	char	**aux;
	int		exit_value;
}	t_env;

typedef struct s_cmd
{
	t_it	i;
	t_env	*env;
	char	**args;
	char	**cmd;
	char	**atrb;

	int		n_cmd;
	int		size;
	int		flag;

	int		words;
	int		quotes;
	int		dollars;
	int		pipes;
	int		double_quotes;
	int		out;
	int		in;
	int		double_in;
	int		double_out;

	int		*input;
	int		in_it;
	int		*output;
	int		out_it;

	int		cmd_start;
	int		pipe_pos;
	int		block_pos;
	int		redir_end;
}	t_cmd;

	// MAIN
void	init_shell(t_cmd *cmd, t_env *env, char	**envp, int *stdio);
void	init_args(t_cmd	*cmd);
void	print(t_cmd	*cmd);
void	ft_choped(t_cmd	*args, t_env *env, char	*prompt);
void	my_signal(int sig);
void	cut_stdio(int sig);
void	getstdio(int *stdio);
void	resetstdio(int *stdio);
int		ft_check_prompt(t_env *env, char *prompt);

	// GET_TOKEN
void	get_token(t_cmd	*cmd, char *prompt);
void	get_inter(t_cmd *cmd, t_env *env);

	// GET_DATA
int		get_data(t_cmd	*args, char	*prompt, int it);
int		i_cwords(t_cmd *cmd, char *prompt, int pos);
int		i_qwords(t_cmd *cmd, char *prompt, int pos);
int		i_dqwords(t_cmd	*cmd, char *prompt, int pos);
int		i_sp(t_cmd *cmd, char *prompt, int i);
int		i_dollars(t_cmd	*cmd, char *prompt, int pos);

	// LEXER
char	*ft_append_both_sides(char	*str);
char	*ft_append_left_side(char	*str);
char	*clean_words(t_cmd *cmd, char *prompt, int pos);
char	*quotes_lexer(t_cmd	*cmd, char *prompt, int pos);
char	*double_quotes_lexer(t_cmd *cmd, char *prompt, int pos);
char	*pipes_lexer(t_cmd *cmd, char *prompt, int pos);
char	*one_lexer(t_cmd *cmd, char *prompt, int pos);
char	*two_lexer(t_cmd *cmd, char	*prompt, int pos);

	// CMD
void	ft_selector(t_cmd *cmd, t_env *env);
int		init_cmd(t_cmd	*cmd, t_env	*env);
void	exec(char **cmd, t_env *env);
int		exec_cmd(t_cmd *cmd, t_env *env);
int		open_fd(t_cmd *cmd);
char	*ft_stephen_jokin(t_cmd	*cmd, int i);
int		find_sp(char **args, int i);
int		error_code(char *cmd, t_env	*env);
int		ft_redir(int pos, char	**args, t_cmd *cmd, int	*checker);
void	close_str(char	**ar, int end, int sp);
int		ft_check_redir(char **cmd, int cmd_start);
int		find_env(int p_ar, int p_str, t_cmd	*cmd, t_env	*env);
int		get_name_start(char	*str);
int		get_name_end(char *str);
void	ft_refill_env(t_env	*env, char	**aux, int i);

	// PIPEX
void	ft_pipe(t_cmd *cmd, t_env *env, int pos, int check);
int		find_pipe(char **args, int i);
void	ft_adult(t_cmd	*cmd, t_env	*env, int cmd_pos);
void	ft_child(t_cmd *cmd, t_env *env, int *fd, int cmd_start);
char	*ft_path(char **enviroment_path);
void	pipe_error(t_cmd *cmd, t_env *env);
int		ft_string_trader(t_cmd *cmd, int start);
void	atrb_fill(t_cmd	*cmd, int pipe_pos, int block_pos, int redir_end);
int		ft_checker(char	*str);
int		get_last_redir(char	**str, int pos);
void	error(char *error);

	// FREE_ARGS
void	free_args(t_cmd	*args);

	//BUILTINGS
int		ft_builtings(char **args, t_cmd *cmd, t_env *env, int open);

	//PWD
int		ft_pwd(t_cmd *cmd, int open);

	//ECHO
int		ft_echo(t_cmd *args, char **cmd, int open);

	//ENV
int		ft_env(t_cmd *cmd, t_env *env, int open);
int		get_name_len(char *str);
char	*ft_find_home(char *str, t_env *env);

	//EXIT
int		ft_exit(t_cmd *args, char **cmd, int open);

	//CD
int		ft_cd(char **cmd, t_cmd *args, t_env *env);
int		is_directory(char *path, t_env *env);

	//EXPORT
int		ft_export(t_env *env, char *content, char *cmd);
int		content_check(t_env *env, char *content, char *cmd);
void	print_export(char **env);

	//UNSET
int		ft_unset(t_env *env, char *content);

	// OUTPUT
void	ft_descriptor_error(t_cmd	*cmd, int i);
int		ft_output(t_cmd	*cmd, int i);
int		ft_doutput(t_cmd *cmd, int i);
	// INPUT
int		ft_input(t_cmd *cmd, int i);
int		ft_dinput(t_cmd	*cmd, int i);

#endif
