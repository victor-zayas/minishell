/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/18 13:42:10 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	init_args(t_cmd	*cmd)
{
	cmd->size = 0;
	cmd->words = 0;
	cmd->quotes = 0;
	cmd->double_quotes = 0;
	cmd->pipes = 0;
	cmd->lesser = 0;
	cmd->greater = 0;
}

void	ft_lexer(t_cmd	*args, char	*prompt)
{
	int	*i;
	
	i = malloc(sizeof(int *));
	(*i) = -1;
	while(prompt[++(*i)])
	{
		if((prompt[(*i)] != '\'') && (prompt[(*i)] != '"') &&
				(prompt[(*i)] != '>')  && (prompt[(*i)] != '<') 
					&& (prompt[(*i)] != '|'))
			prompt = clean_words(args, prompt, i);
		if((prompt[(*i)] == '\'') && prompt[(*i)] && args->quotes > 0)
			prompt = quotes_lexer(args, prompt, i);
		if (prompt[(*i)] == '"' && prompt[(*i)])
			prompt = double_quotes_lexer(args, prompt, i);
		if (prompt[(*i)] == '|' && prompt[(*i)])
			prompt = pipes_lexer(args, prompt, i);
		if (prompt[(*i)] == '<' && prompt[(*i)])
			prompt = in_lexer(args, prompt, i);
		if (prompt[(*i)] == '>' && prompt[(*i)])
			prompt = out_lexer(args, prompt, i);
	}
	free(i);
}

void	get_token(t_cmd	*cmd, char	*prompt)
{
	cmd->args = (char	**)malloc(sizeof(char	*) * (cmd->words + cmd->quotes
			 + cmd->double_quotes + cmd->pipes + cmd->lesser + 
			 	cmd->greater + 1));
	printf("\n\n				TOKENS: %d\n\n", (cmd->words + cmd->quotes
			 + cmd->double_quotes + cmd->pipes + cmd->lesser + 
			 	cmd->greater + 1));
	ft_lexer(cmd, prompt);
	cmd->args[cmd->size] = NULL;
	cmd->size = 0;
}

void	free_args(t_cmd	*args)
{
	int	i;

	i = 0;
	while(args->args[i])
		free(args->args[i++]);
	free(args->args);
}
