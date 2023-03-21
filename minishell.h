/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:41:08 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/21 17:50:40 by jaizpuru         ###   ########.fr       */
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

typedef struct s_cmd
{
	t_it	i;
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
	int		lesser;
	int		greater;
	int		double_in;
	int		double_out;

	int		*input;
	int		in_it;
	int		*output;
	int		out_it;
}	t_cmd;

typedef struct s_env
{
	char	*oldpwd;
	char	*pwd;
	char	**env;
	char	**aux;
	int		exit_value;
}	t_env;

	// MAIN
void	init_shell(t_cmd	*new, t_env	*env, char	**envp);
void	init_args(t_cmd	*cmd);
void	print(t_cmd	*cmd);
void	ft_choped(t_cmd	*args, t_env *env, char	*prompt);
void	my_signal(int sig);

	//LEXER
	// GET_TOKEN
void	get_token(t_cmd	*cmd, char *prompt);
void	get_inter(t_cmd *cmd, t_env *env);

	// GET_DATA
int		get_data(t_cmd	*args, char	*prompt);
int		i_cwords(t_cmd *cmd, char *prompt, int pos);
int		i_qwords(t_cmd *cmd, char *prompt, int pos);
int		i_dqwords(t_cmd	*cmd, char *prompt, int pos);
int		i_sp(t_cmd *cmd, char *prompt, int i);
int		i_dollars(t_cmd	*cmd, char *prompt, int pos);

	// LEXER
char	*clean_words(t_cmd *cmd, char *prompt, int pos);
char	*quotes_lexer(t_cmd	*cmd, char *prompt, int pos);
char	*double_quotes_lexer(t_cmd *cmd, char *prompt, int pos);
char	*pipes_lexer(t_cmd *cmd, char *prompt, int pos);
char	*one_lexer(t_cmd *cmd, char *prompt, int pos);
char	*two_lexer(t_cmd *cmd, char	*prompt, int pos);

	// CMD
void	ft_selector(t_cmd *cmd, t_env *env);
int		exec_cmd(t_cmd	*cmd, t_env	*env);
void	open_fd(t_cmd	*cmd);
char	*ft_stephen_jokin(t_cmd	*cmd, int i);
int		find_pipe(char **args, int i);
void	ft_pipe(t_cmd *cmd, t_env *env, int pos);
int		error_code(char *cmd, t_env	*env);

	// PIPEX
void	exec(char **cmd, t_env	*env);
void	ft_child(t_cmd *cmd, t_env *env, int *fd);
char	*ft_path(char **enviroment_path);
char	*get_cmd(char *arguments, char **enviroment);
void	error(char *error);
void	ft_fd(t_cmd	*cmd, t_env	*env);
int		find_env(int p_ar, int p_str, t_cmd	*cmd, t_env	*env);
int		get_name_end(char	*str);
int		get_name_start(char	*str);

	// FREE_ARGS
void	free_args(t_cmd	*args);

	//BUILTINGS
int		ft_builtings(char **args, t_cmd *cmd, t_env *env);

	//PWD
int		ft_pwd(void);

	//ECHO
int		ft_echo(char **cmd);

	//ENV
int		ft_env(t_env *env);
int		get_name_len(char *str);
char	*ft_find_home(char *str, t_env *env);

	//EXIT
int		ft_exit(char **cmd);

	//CD
int		ft_cd(char **cmd, t_cmd *args, t_env *env);
int		is_directory(char *path, t_env *env);

	//EXPORT
int		ft_export(t_env *env, char *content, char *cmd);
int		content_check(t_env *env, char *content, char *cmd);
void	print_export(char **env);

	//UNSET
int		ft_unset(t_env *env, char *content);

	// REDIRECTIONS
void	ft_output(t_cmd	*cmd, int i);
void	ft_input(t_cmd	*cmd, int i);

#endif

	//  __unused -> Variables not used
	//  __attribute__((unused)) -> Variables not used

	// TO _ DO
		// 1. EXIT STATUS
			// Exit Status can return a variety of differet numbers, depending on the outcome of the input:
			// How can we get the Exit Status of an Executed Command?
			// Simple, we just need to transfer the exit value of the child process (responsible for executing the command),
			// to the parent process.

			// To do this, reading some lines of the wait(2) manual of Linux is preferible.
			// We basically use a paramater inside wait & waitpid functions (int &wstatus), an integer that is most useful when we need to handle errors
			// With this integer and some macros, we can inspect the value that the child process WAS EXITED WITH!

			// We just need to put this value inside our structure, so to do that, we need to make the "exec_cmd" function return the value for the structure to handle it from above
			// or just give a pointer to the function.

			// Personally, I prefer to make it return the integer, so the type of the function is taken advantage of.
			// So it would look like this:
			// int	exec_cmd(char **cmd, t_env *env)
		// 2. REDIRECCIONES
			//format : "[in_command / out_command] [output / input]".
		// 3. PARSEO
			// lexer-> double quotes: [echo "$PWD $USER $TERM ..." | wc]

	// DONE
		// add int in exec funct to controll cmd error, if 1 fail, pipes stop.
			// Not needed anymore!
			// Bash executes the last command no matter 
			// what the input it is given by a pipe!
			// So we have it as we should -> Check.

	// STEPS TO MAKE MINISHELL
		//lexer(); //comillas simples, comillas dobles, pipes, redirecciones
		// 1.er paso
			//encuentro comilla, leo hasta la siguiente comilla 
			//(si no hay doy error), lo meto en un token
			//p.e.: ls 'hola buenas "tardes $hehe"' | pwd 
			//token 1 = ls, token 2 = 'hola buenas "tardes $hehe"' token 3 = pwd
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

	//FALLOS
	//SHLVL doesn't aument

	//OPTIONAL
	// delete ctrl c on signal
	// cmd options interpretate all exec options & ignore inextents