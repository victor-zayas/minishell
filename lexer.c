/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/24 19:44:36 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	tmp = ft_substr(prompt, pos, ft_strlen(prompt) - pos);
	free(prompt);
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
	cmd->args[cmd->size++] = ft_substr(prompt, (start), pos - start + 1);
	tmp = ft_substr(prompt, (pos + 1), ft_strlen(prompt) - pos + 1);
	free(prompt);
	return (tmp);
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
	free(prompt);
	return (tmp);
}

char	*pipes_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	int		aux;
	char	*tmp;

	printf("pipaslexer: %s\n", prompt);
	aux = (pos);
	cmd->args[cmd->size++] = ft_substr(prompt, aux, 1);
	tmp = ft_substr(prompt, (aux + 1), ft_strlen(prompt) - aux + 1);
	free(prompt);
	return (tmp);
}
