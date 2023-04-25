/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/25 11:52:59 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getdollar(t_cmd	*cmd, char	*prompt, int i)
{
	int		start;
	char	*aux;
	int		len;

	start = i;
	aux = 0;
	while (prompt[i] && prompt[i] != '"' && prompt[i] != '<'
		&& prompt[i] != '|' && prompt[i] != '>' && prompt[i] != '\''
		&& prompt[i] != ' ' && prompt[i] != '\t')
		i++;
	aux = ft_append_both_sides(ft_substr(prompt, start, i - start + 1));
	cmd->i.i1 = 0;
	cmd->args[cmd->size++] = ft_strdup(aux);
	free(aux);
	cmd->i.i1 = i;
	len = ft_strlen(prompt) - i + 1;
	return (ft_append_left_side(ft_substr(prompt, (i), len)));
}

char	*clean_words(t_cmd	*cmd, char *prompt, int pos)
{
	char	*tmp;
	int		start;

	start = (pos);
	while (prompt[pos] != '\'' && prompt[pos] != '"' && prompt[pos] != '<'
		&& prompt[pos] != '|' && prompt[pos] != '>' && prompt[pos]
		&& prompt[pos] != ' ' && prompt[pos] != '\t')
		pos++;
	if (prompt[pos] == '\0' && (prompt[pos - 1] == ' '
			|| prompt[pos - 1] == '\t'))
		return (free(prompt), ft_strdup(""));
	cmd->args[cmd->size++] = ft_substr(prompt, start, pos - start);
	tmp = ft_substr(prompt, pos, ft_strlen(prompt) - pos + 1);
	free(prompt);
	return (tmp);
}

char	*quotes_checker(char	*prompt, int pos)
{
	char	*tmp;

	tmp = 0;
	if (pos == 1)
	{
		tmp = ft_substr(prompt, (pos + 1), ft_strlen(prompt) - pos + 1);
		free(prompt);
		return (tmp);
	}
	return (tmp);
}

char	*quotes_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	char	*tmp;
	int		start;

	start = (pos);
	(pos)++;
	while (prompt[pos] != '\'' && prompt[pos])
		(pos)++;
	if (pos == 1)
	{
		tmp = ft_substr(prompt, (pos + 1), ft_strlen(prompt) - pos + 1);
		free(prompt);
		return (tmp);
	}
	cmd->args[cmd->size++] = ft_substr(prompt, (start), pos - start + 1);
	tmp = ft_substr(prompt, (pos + 1), ft_strlen(prompt) - pos + 1);
	free(prompt);
	return (tmp);
}

char	*double_quotes_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	char	*tmp;
	int		start;

	tmp = 0;
	start = (pos);
	(pos)++;
	while (prompt[pos] != '"' && prompt[pos])
	{
		if (prompt[pos] == '$')
		{
			tmp = ft_getdollar(cmd, prompt, pos);
			pos = cmd->i.i1;
			free(prompt);
			return (tmp);
		}
		(pos)++;
	}
	if (pos == 1)
		return (quotes_checker(prompt, pos));
	cmd->args[cmd->size++] = ft_substr(prompt, start, pos - start + 1);
	tmp = ft_substr(prompt, (pos + 1), ft_strlen(prompt) - pos + 1);
	free(prompt);
	return (tmp);
}
