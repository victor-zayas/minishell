#ifndef MINISHELL_H
# define MINISHELL_H

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef	struct s_cmd
{
	char	**args;
	int		size;
	int		quotes;
	int		double_quotes;
	int		pipes;
}		t_cmd;

	// MAIN
void	init_args(t_cmd	*new);
void	print(t_cmd	*cmd);
void	ft_chopeadito(char	*prompt, char	**env, t_cmd	*args);

	// GET_TOKEN
void	get_token(t_cmd	*cmd, char	*line);

	// GET_DATA
int		get_quotes(t_cmd	*args, char	*line);
int		get_double_quotes(t_cmd	*args, char	*line);
int		get_pipes(t_cmd	*args, char	*line);

	// LEXER
char	*quotes_lexer(t_cmd	*cmd, char	*line, int	*pos);
char	*double_quotes_lexer(t_cmd	*cmd, char	*line, int	*pos);
char	*pipes_lexer(t_cmd	*cmd, char	*line, int	*pos);

	// PIPEX
void	exec(t_cmd	*token, char	**env);
char	*ft_path(char	**enviroment_path);
char	*get_cmd(char	*arguments, char	**enviroment);

	// FREE_ARGS
void	free_args(t_cmd	*args);




	// TO _ DO

	//lexer(); //optional //comillas simples, comillas dobles, pipes
		//encuentro comilla, leo hasta la siguiente comilla (si no hay doy error), lo meto en un token
			//p.e.: ls 'hola buenas "tardes $hehe"' pwd token 1 = ls, token 2 = 'hola buenas "tardes $hehe"' token 3 = pwd
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