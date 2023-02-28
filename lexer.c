/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/28 16:28:25 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_append2(char	*str, int i)
{
	char	*aux;
	int		pos;
	int		start;

	start = i;
	pos = -1;
	while (str[i])
		i++;
	aux = (char *)malloc(sizeof(char) * (i));
	while(i >= start)
		aux[++pos] = str[start++];
	aux[pos] = '\0';
	return (aux);
}

int	ft_append(t_cmd	*cmd, char	*str, int i)
{
	char	*aux;
	int		pos;
	int		i2;

	i2 = 0;
	pos = i;
	pos++;
	aux = (char *)malloc(sizeof(char) * (ft_strlen(str) + 3));
	while (str[pos] != '\'' && str[pos] != '"' && str[pos] != ' '
		&& str[pos] != '|' && str[pos] != '>' && str[pos] != '\t'
		&& str[pos] != '<' && str[pos] != '$' && str[pos] != '\0')
				pos++;
	aux[i2] = '\"';
	while(pos >= i)
		aux[++i2] = str[i++];
	aux[i2] = '\"';
	aux[i2 + 1] = '\0';
	cmd->args[cmd->size++] = ft_strdup(aux);
	free (aux);
	return (pos);
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
	{
		/* if (prompt[pos] == '$' && prompt[pos])
		{
			pos = ft_append(cmd, prompt, pos);
			if (!prompt[pos + 1])
			{
				free(prompt);
				return (ft_strdup(""));
			}
			tmp = ft_append2(prompt, pos + 1);
			printf("tmp -> %s\n", tmp);
			free(prompt);
			return (tmp);
		} */
		(pos)++;
	}
	cmd->args[cmd->size++] = ft_substr(prompt, start, pos - start + 1);
	tmp = ft_substr(prompt, (pos + 1), ft_strlen(prompt) - pos + 1);
	free(prompt);
	return (tmp);
}
