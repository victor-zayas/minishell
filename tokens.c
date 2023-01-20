/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedgedog <hedgedog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/20 19:17:55 by hedgedog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	int	i;

	i = 0;
	while (prompt[i])
	{
		while (prompt[i] == ' ' || prompt[i] == '\t')
			i++;
		if ((prompt[i] != '\'') && (prompt[i] != '"')
			&& (prompt[i] != '>') && (prompt[i] != '<')
			&& (prompt[i] != '|'))
			prompt = clean_words(args, prompt, i);
		else if ((prompt[i] == '\'') && prompt[i])
			prompt = quotes_lexer(args, prompt, i);
		else if (prompt[i] == '"' && prompt[i])
			prompt = double_quotes_lexer(args, prompt, i);
		else if (prompt[i] == '|' && prompt[i])
			prompt = pipes_lexer(args, prompt, i);
		else if (prompt[i] == '<' && prompt[i])
			prompt = in_lexer(args, prompt, i);
		else if (prompt[i] == '>' && prompt[i])
			prompt = out_lexer(args, prompt, i);
		i = 0;
	}
}

void	get_token(t_cmd	*cmd, char	*prompt)
{
	cmd->args = (char **)malloc(sizeof(char *) * (cmd->words + cmd->quotes
				+ cmd->double_quotes + cmd->pipes + cmd->lesser
				+ cmd->greater + 1));
	// printf("\n\n				TOKENS: %d\n\n", (cmd->words + cmd->quotes
	//		 + cmd->double_quotes + cmd->pipes + cmd->lesser + 
	//		 	cmd->greater + 1));
	ft_lexer(cmd, prompt);
	cmd->args[cmd->size] = NULL;
	cmd->size = 0;
}

void	free_args(t_cmd	*args)
{
	int	i;

	i = 0;
	while (args->args[i])
		free(args->args[i++]);
	free(args->args);
}
