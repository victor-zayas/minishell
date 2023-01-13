/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/13 13:29:20 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	init_args(t_cmd	*new)
{
	new->args = NULL;
	new->size = 0;
	new->quotes = 0;
}

void	get_token(t_cmd	*cmd, char	*line)
{
	int	*i;
	int	start;
	int	j;

	i = malloc(sizeof(int *));
	(*i) = -1;
	j = 0;
	start = 0;
	cmd->args = (char	**)malloc(sizeof(char	*) * (cmd->quotes + cmd->double_quotes + cmd->pipes + 1)); // IMPORTANT!
	while(line[++(*i)])
	{
		if((line[(*i)] == '\'') && line[(*i)])
			line = quotes_lexer(cmd, line, i);
		if (line[(*i)] == '"' && line[(*i)])
			line = double_quotes_lexer(cmd, line, i);
		if (line[(*i)] == '|' && line[(*i)]) 
			line = pipes_lexer(cmd, line, i);
	}
	cmd->args[cmd->size] = NULL;
	cmd->size = 0;
	free(i);
}

void	free_args(t_cmd	*args)
{
	int	i;

	i = 0;
	while(args->args[i])
		free(args->args[i++]);
	free(args->args);
}
