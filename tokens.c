/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/23 20:24:39 by jaizpuru         ###   ########.fr       */
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
	cmd->dollars = 0;
	cmd->double_redir = 0;
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
			prompt = one_lexer(args, prompt, i);
		else if (((prompt[i] == '<' && prompt[i + 1] == '<')
				|| (prompt[i] == '>' && prompt[i + 1] == '>')) && prompt[i])
			prompt = two_lexer(args, prompt, i);
		else if ((prompt[i] == '<' || prompt[i] == '>') && prompt[i])
			prompt = one_lexer(args, prompt, i);
		i = 0;
	}
	free(prompt);
}

void	get_token(t_cmd	*cmd, char	*prompt)
{
	cmd->args = (char **)malloc(sizeof(char *) * (cmd->words + cmd->quotes
				+ cmd->double_quotes + cmd->pipes + cmd->lesser
				+ cmd->greater + cmd->dollars + cmd->double_redir + 1));
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
