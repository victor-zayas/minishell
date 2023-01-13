/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/13 13:20:49 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quotes_lexer(t_cmd	*cmd, char	*line, int	*pos)
{
	int	start;
	int	aux;

	aux = (*pos);
	start = (*pos);
	aux++;
	while (line[aux] != '\'' && line[aux])
				aux++;
	cmd->args[cmd->size++] = ft_substr(line, start, aux - start + 1);
	char *tmp = ft_substr(line, aux + 1, ft_strlen(line) - aux + 1);
	line = ft_strdup(tmp);
	free(tmp);
	*pos = 0;
	return (line);
}

char	*double_quotes_lexer(t_cmd	*cmd, char	*line, int	*pos)
{
	int	start;
	int	aux;

	aux = (*pos);
	start = (*pos);
	aux++;
	while (line[aux] != '"' && line[aux])
				aux++;
	cmd->args[cmd->size++] = ft_substr(line, start, aux - start + 1);
	char *tmp = ft_substr(line, aux + 1, ft_strlen(line) - aux + 1);
	line = ft_strdup(tmp);
	free(tmp);
	*pos = 0;
	return (line);
}

char	*pipes_lexer(t_cmd	*cmd, char	*line, int	*pos)
{
	int		aux;
	char 	*tmp;

	aux = (*pos);
	cmd->args[cmd->size++] = ft_substr(line, aux, 2);
	tmp = ft_substr(line, aux + 1, ft_strlen(line) - aux + 1);
	/* line = ft_strdup(tmp); */
	/* start = pos;
	while (line[pos] != '|' && line[pos])
				pos++;
	cmd->args[cmd->size++] = ft_substr(line, start, pos - start + 1);
	tmp = ft_substr(line, pos + 1, ft_strlen(line) - pos + 1);
	line = ft_strdup(tmp); */
	*pos = 1;
	return (line);
}
