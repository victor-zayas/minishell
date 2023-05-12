/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 12:12:47 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief	This function gets dollar tokens inside double quote cases,
 * 			the content inside double quotes is trimmed and stored as token.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param i Position of the chr inside prompt.
 * @return char* The prompt is cut so the new token won't appear.
 */
char	*ft_getdollar(t_cmd	*cmd, char *prompt, int i)
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

/**
 * @brief	This function iterates until any sp-chr or NULL is found,
 * 			so then we can allocate and retrieve the token to cmd.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param pos Position of the chr inside prompt.
 * @return char* The prompt is cut so the new token won't appear.
 */
char	*clean_words(t_cmd *cmd, char *prompt, int pos)
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


/**
 * @brief	The function shortens the prompt, if the given case any quotes
 * 			are next to each other without any content[""].
 * 
 * @param prompt String that we get from the CL.
 * @param pos Position of the chr inside prompt.
 * @return char* A string without empty double quotes is returned.
 */
char	*quotes_checker(char *prompt, int pos)
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

/**
 * @brief	This function iterates until any simple quote or NULL is found,
 * 			so then we can allocate and retrieve the token to cmd.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param pos Position of the chr inside prompt.
 * @return char* The prompt is cut so the new token won't appear.
 */
char	*quotes_lexer(t_cmd	*cmd, char *prompt, int pos)
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

/**
 * @brief	This function iterates until any double quote or NULL is found,
 * 			so then we can allocate and retrieve the token to cmd.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param pos Position of the chr inside prompt.
 * @return char* The prompt is cut so the new token won't appear.
 */
char	*double_quotes_lexer(t_cmd *cmd, char *prompt, int pos)
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
