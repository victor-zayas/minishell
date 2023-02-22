/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:41:08 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/22 20:06:22 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_cmd
{
	char	**args;
	char	**cmd;
	char	**atrb;
	int		n_cmd;
	int		size;

	int		words;
	int		quotes;
	int		double_quotes;
	int		pipes;
	int		lesser;
	int		greater;
	int		dollars;
}		t_cmd;

typedef struct s_env
{
	char	*oldpwd;
	char	*pwd;
	char	**env;
}	t_env;

	// MAIN
void	init_args(t_cmd	*new);
void	print(t_cmd	*cmd);
void	ft_chopeadito(t_cmd	*args, t_env *env, char	*prompt);

	//LEXER
	// GET_TOKEN
void	get_token(t_cmd	*cmd, char	*prompt);
void	get_inter(t_cmd *cmd, t_env *env);

	// GET_DATA
void	get_data(t_cmd *args, char *prompt);
int		i_cwords(t_cmd *cmd, char *prompt, int pos);
int		i_qwords(t_cmd *cmd, char *prompt, int pos);
int		i_dqwords(t_cmd	*cmd, char *prompt, int pos);
int		i_pipes(t_cmd *cmd, int i);
int		i_in(t_cmd *cmd, int i);
int		i_out(t_cmd	*cmd, int i);
int		i_dollars(t_cmd	*cmd, char *prompt, int pos);

	// LEXER
char	*clean_words(t_cmd *cmd, char *prompt, int pos);
char	*quotes_lexer(t_cmd	*cmd, char *prompt, int pos);
char	*double_quotes_lexer(t_cmd *cmd, char *prompt, int pos);
char	*pipes_lexer(t_cmd *cmd, char *prompt, int pos);
char	*out_lexer(t_cmd *cmd, char *prompt, int pos);
char	*in_lexer(t_cmd	*cmd, char *prompt, int pos);

	// CMD
void	ft_selector(t_cmd *cmd, t_env *env);
void	exec_cmd(char **cmd, char **enviroment);
char	*ft_stephen_jokin(t_cmd	*cmd, int i);
int		find_pipe(char **args, int i);
void	ft_pipe(t_cmd *cmd, t_env *env, int pos);

	// PIPEX
void	exec(char **cmd, char **env);
void	ft_child(char **cmd, char **enviroment1, int *fds1);
void	ft_adult(char **cmd, char **enviroment2, int *fds2);
char	*ft_path(char **enviroment_path);
char	*get_cmd(char *arguments, char **enviroment);
void	error(char *error);
void	ft_fd(t_cmd	*cmd, t_env	*env);

	// FREE_ARGS
void	free_args(t_cmd	*args);

	//BUILTINGS
void	ft_builtings(t_cmd *args, t_env *env);

	//PWD
void	ft_pwd(void);

	//ECHO
void	ft_echo(t_cmd *args);

	//ENV
void	ft_env(t_env *env);

	//EXIT
int		ft_exit(t_cmd *args);

	//CD
bool	ft_cd(t_cmd *args, t_env *env);

	//EXPORT
void	ft_export(t_env	*env, char *content);
int		content_check(t_env	*env, char *content);
void	print_export(char **env);

	//UNSET
void	ft_unset(t_env *env, char *content);

#endif

	//  __unused -> Variables not used
	//  __attribute__((unused)) -> Variables not used

	// TO _ DO
		// rebuild commad without spaces and add one between cmds;
		// add int in exec funct to controll cmd error, if 1 fail, pipes stop.
		// exit value estatus
		// redirections
		// PARSEO
	//lexer(); //comillas simples, comillas dobles, pipes, redirecciones
	// 1.er paso
		//encuentro comilla, leo hasta la siguiente comilla 
		//(si no hay doy error), lo meto en un token
		//p.e.: ls 'hola buenas "tardes $hehe"' 
		//pwd token 1 = ls, token 2 = 'hola buenas "tardes $hehe"' token 3 = pwd
			//p.e.: ls -la  'h''u'
			//p.e.:               ls    ' '  -l a  'h'
			//p.e.:   - l a a'' a
			//p.e: && prompt[i] == '\t'
			//$ recive numeros o letras no caracteres especiales. 
			//if $en mstring cortar.
			//while (prompt)
			//if (prompt[i] == '\'') -> else if 
			//(prompt[i] == '"') else if (prompt[i] == '|') else
	//builtings();
	//parser();
	//redirs();
	//execute();

	// PIPEX
	//args = ft_split(aux, ' ');
	//printf("cual es el resultado de args -> %s\n", *args);
	//path = get_cmd(*args, env);
	//execve(path, args, env);
