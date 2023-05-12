/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:41:08 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/05/12 10:23:52 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <termios.h>
# include <sys/termios.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "structs.h"

// MAIN
	// INIT
void	init_shell(t_cmd *cmd, t_env *env, char	**envp, int *stdio);

	// STDIO_RELATED
void	getstdio(int *stdio);
void	resetstdio(int *stdio);

	// SIGNAL_RELATED
void	cut_stdio(int sig);
void	my_signal(int sig);
void	my_signal_mod(int sig);
void	my_signal_exit(int sig);

	// BONUS_FORMAT_CHECKER
int		ft_check_prompt(char *prompt);

	// PRINT
void	print(t_cmd	*cmd);

	// LEXER, PARSER, EXECUTE
void	ft_choped(t_cmd	*args, t_env *env, char	*prompt);

// GET_TOKEN
void	get_token(t_cmd	*cmd, char *prompt);
void	ft_trimexpand(t_cmd *cmd, t_env *env);

// GET_DATA
	// INDEX
int		get_data(t_cmd	*args, char	*prompt, int it);

	// ITERATORS
int		i_cwords(t_cmd *cmd, char *prompt, int pos);
int		i_qwords(t_cmd *cmd, char *prompt, int pos);
int		i_dqwords(t_cmd	*cmd, char *prompt, int pos);
int		i_sp(t_cmd *cmd, char *prompt, int i);
int		i_dollars(t_cmd	*cmd, char *prompt, int pos);

// LEXER
	// SEGMENTATION RELATED
char	*clean_words(t_cmd *cmd, char *prompt, int pos);
char	*quotes_lexer(t_cmd	*cmd, char *prompt, int pos);
char	*double_quotes_lexer(t_cmd *cmd, char *prompt, int pos);
char	*pipes_lexer(t_cmd *cmd, char *prompt, int pos);
char	*one_lexer(t_cmd *cmd, char *prompt, int pos);
char	*two_lexer(t_cmd *cmd, char	*prompt, int pos);
	// UTILS
char	*ft_append_both_sides(char	*str);
char	*ft_append_left_side(char	*str);

// CMD
	// INDEX
void	ft_selector(t_cmd *cmd, t_env *env);

	// MAS
int		init_cmd(t_cmd	*cmd, t_env	*env);
int		find_sp(char **args, int i);
int		find_pipe(char **args, int i);

	// EXEC
int		exec_cmd(t_cmd *cmd, t_env *env);
void	exec(char **cmd, t_env *env);
char	*ft_path(char **enviroment_path);

	// REDIR RELATED
int		open_fd(t_cmd *cmd);
int		ft_redir(int pos, char	**args, t_cmd *cmd);
int		ft_check_redir(char **cmd, int cmd_start);
void	ft_get_heredoc(char	*arg);

	// TOKEN RELATED
char	*ft_stephen_jokin(t_cmd	*cmd, int i);
void	close_str(char	**ar, int end, int sp);

	// ERROR
int		error_code(char *cmd, t_env	*env);

// ENV
	// INDEX
int		find_env(int p_ar, int p_str, t_cmd	*cmd, t_env	*env);

	// UTILS
int		get_name_start(char	*str);
int		get_name_end(char *str);
void	ft_refill_env(t_env	*env, char	**aux, int i);

// PIPEX
	// INDEX
void	ft_pipe(t_cmd *cmd, t_env *env, int pos, int check);
void	init_cmd_pipes(t_cmd	*cmd, int pipe_end, int sp_end);

	// FORK LOOP
void	ft_adult(t_cmd	*cmd, t_env	*env, int cmd_pos);
void	ft_child(t_cmd *cmd, t_env *env, int *fd, int cmd_start);

	// ERROR RELATED
void	error(char *error);
void	pipe_error(void);

	// TOKEN
int		ft_string_trader(t_cmd *cmd, int start);
void	atrb_fill(t_cmd	*cmd, int pipe_pos, int block_pos);

	// REDIR RELATED
int		get_last_redir(char	**str, int pos);

// FREE_ARGS
void	free_args(t_cmd	*args);

//BUILTINGS
int		ft_builtings(char **args, t_cmd *cmd, t_env *env, int open);
int		ft_checker(char	*str);

	//PWD
int		ft_pwd(t_cmd *cmd, int open);

	//ECHO
int		ft_echo(t_cmd *args, char **cmd, int open);

	//ENV
char	**ft_env_strdup(char **str);
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
