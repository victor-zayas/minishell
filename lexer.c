/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/12 15:44:59 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*quotes_lexer(t_cmd	*cmd, char	*line, int	pos)
{
	int	start;

	start = pos;
	pos++;
	while (line[pos] != '\'' && line[pos])
				pos++;
	cmd->args[cmd->size++] = ft_substr(line, start, pos - start + 1);
	char *tmp = ft_substr(line, pos + 1, ft_strlen(line) - pos + 1);
	line = ft_strdup(tmp);
	printf("line -> %s\n", cmd->args[cmd->size - 1]);
	return (line);
}

char	*double_quotes_lexer(t_cmd	*cmd, char	*line, int	pos)
{
	int	start;

	start = pos;
	printf("pos -> %d\n", pos);
	pos++;
	while (line[pos] != '"' && line[pos])
				pos++;
	cmd->args[cmd->size++] = ft_substr(line, start, pos - start + 1);
	char *tmp = ft_substr(line, pos + 1, ft_strlen(line) - pos + 1);
	line = ft_strdup(tmp);
	printf("line -> %s\n", cmd->args[cmd->size - 1]);
	return (line);
}

char	*pipes_lexer(t_cmd	*cmd, char	*line, int	pos)
{
	int	start;

	start = pos;
	pos++;
	while (line[pos] != '|' && line[pos])
				pos++;
	cmd->args[cmd->size++] = ft_substr(line, start, pos - start + 1);
	char *tmp = ft_substr(line, pos + 1, ft_strlen(line) - pos + 1);
	line = ft_strdup(tmp);
	printf("line -> %s\n", cmd->args[cmd->size - 1]);
	return (line);
}
