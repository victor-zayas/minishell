#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef	struct s_cmd
{
	char	**args;
	char	**cmds;
	int		size;

	int		words;
	int		quotes;
	int		double_quotes;
	int		pipes;

	int		lesser;
	int		greater;
}		t_cmd;

	// MAIN
void	init_args(t_cmd	*new);
void	print(t_cmd	*cmd);
void	ft_chopeadito(t_cmd	*args, char	*prompt);

	// GET_TOKEN
void	get_token(t_cmd	*cmd, char	*prompt);

	// GET_DATA
void	get_data(t_cmd	*args, char	*prompt);
int		i_cwords(t_cmd	*cmd, char	*prompt, int pos);
int		i_qwords(t_cmd	*cmd, char	*prompt, int pos);
int		i_dqwords(t_cmd	*cmd, char	*prompt, int pos);

	// LEXER
char	*clean_words(t_cmd	*cmd, char	*prompt, int	pos);
char	*quotes_lexer(t_cmd	*cmd, char	*prompt, int	pos);
char	*double_quotes_lexer(t_cmd	*cmd, char	*prompt, int	pos);
char	*pipes_lexer(t_cmd	*cmd, char	*prompt, int	pos);
char	*out_lexer(t_cmd	*cmd, char	*prompt, int	pos);
char	*in_lexer(t_cmd	*cmd, char	*prompt, int	pos);

	// PIPEX
void	exec(t_cmd	*token, char	**env);
char	*ft_path(char	**enviroment_path);
char	*get_cmd(char	*arguments, char	**enviroment);

	// FREE_ARGS
void	free_args(t_cmd	*args);




	// TO _ DO
	// REMOVE POINTERS OF ITERATORS IN GET_DATA

	//lexer(); //optional //comillas simples, comillas dobles, pipes
	// 1.er paso
		//encuentro comilla, leo hasta la siguiente comilla (si no hay doy error), lo meto en un token
			//p.e.: ls 'hola buenas "tardes $hehe"' pwd token 1 = ls, token 2 = 'hola buenas "tardes $hehe"' token 3 = pwd
			//p.e.: ls -la  'h''u'
			//p.e.:               ls    ' '  -l a  'h'
			//p.e.:   - l a a'' a 
			//while (prompt)
				//if (prompt[i] == '\'') -> else if (prompt[i] == '"') else if (prompt[i] == '|') else
	//parser();
	//redirs();
	//execute();

	// PIPEX

	//args = ft_split(aux, ' ');
	//printf("cual es el resultado de args -> %s\n", *args);
	//path = get_cmd(*args, env);
	//execve(path, args, env);

#endif
