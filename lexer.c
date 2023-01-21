/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedgedog <hedgedog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/21 18:18:02 by hedgedog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clean_words(t_cmd	*cmd, char *prompt, int pos)
{
	char	*tmp;
	int		start;
	int		size;

	start = (pos);
	size = ft_strlen(prompt);
	while (prompt[pos] != '\'' && prompt[pos] != '"' && prompt[pos] != '<'
		&& prompt[pos] != '|' && prompt[pos] != '>' && prompt[pos]
		&& prompt[pos] != ' ' && prompt[pos] != '\t')
		pos++;
	if (prompt[pos] == '\0' && (prompt[pos - 1] == ' '
			|| prompt[pos - 1] == '\t'))
		return (ft_strdup(""));
	cmd->args[cmd->size++] = ft_substr(prompt, start, pos - start);
	tmp = ft_substr(prompt, pos, size - pos);
	if(tmp)
		prompt = tmp;
	free(tmp);
	return (prompt);
}

char	*quotes_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	char	*tmp;
	int		start;

	start = (pos);
	(pos)++;
	while (prompt[pos] != '\'' && prompt[pos])
				(pos)++;
	cmd->args[cmd->size++] = ft_substr(prompt, (start), pos - start + 1);
	tmp = ft_substr(prompt, (pos + 1), ft_strlen(prompt) - pos + 1);
	prompt = tmp;
	free(tmp);
	return (prompt);
}

char	*double_quotes_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	char	*tmp;
	int		start;

	start = (pos);
	(pos)++;
	while (prompt[pos] != '"' && prompt[pos])
				(pos)++;
	cmd->args[cmd->size++] = ft_substr(prompt, start, pos - start + 1);
	tmp = ft_substr(prompt, (pos + 1), ft_strlen(prompt) - pos + 1);
	prompt = tmp;
	free(tmp);
	return (prompt);
}

char	*pipes_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	int		aux;
	char	*tmp;

	aux = (pos);
	cmd->args[cmd->size++] = ft_substr(prompt, aux, 1);
	tmp = ft_substr(prompt, (aux + 1), ft_strlen(prompt) - aux + 1);
	prompt = tmp;
	free(tmp);
	return (prompt);
}
