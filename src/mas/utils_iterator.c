/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iterator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:10:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 11:52:51 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief This function skips a number of chrs depending if any special
 * 			chrs have been found inside the prompt.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param i Iterator value set to position of prompt 
 * @return int Returns val of prompt position after sp chr.
 */
int	i_cwords(t_cmd	*cmd, char	*prompt, int pos)
{
	while (prompt[pos] != '\'' && prompt[pos] != '"' && prompt[pos] != ' '
		&& prompt[pos] != '|' && prompt[pos] != '>' && prompt[pos] != '\t'
		&& prompt[pos] != '<' && prompt[pos] != '$' && prompt[pos] != '\0')
				pos++;
	cmd->words += 1;
	return (pos);
}

/**
 * @brief This function skips a number of chrs depending if any simple quote
 * 			has been found inside the prompt, else (-1) error is returned.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param i Iterator value set to position of prompt 
 * @return int Returns val of prompt position after sp chr.
 */
int	i_qwords(t_cmd	*cmd, char	*prompt, int pos)
{
	if (!prompt[pos + 1])
		return (-1);
	(pos)++;
	while (prompt[pos] != '\'' && prompt[pos])
				pos++;
	if (prompt[pos] == '\'')
		cmd->quotes += 1;
	else
		return (-1);
	pos++;
	return (pos);
}

/**
 * @brief This function skips a number of chrs depending if any double quote
 * 			has been found inside the prompt, else (-1) error is returned.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param i Iterator value set to position of prompt 
 * @return int Returns val of prompt position after sp chr.
 */
int	i_dqwords(t_cmd	*cmd, char	*prompt, int pos)
{
	if (!prompt[pos + 1])
		return (-1);
	cmd->flag = 1;
	pos++;
	while (prompt[pos] != '"' && prompt[pos])
	{
		if (prompt[pos] == '$')
		{
			if (cmd->flag == 0)
				cmd->dollars++;
			else
				cmd->flag = 0;
		}
		pos++;
	}
	if (prompt[pos] == '"')
		cmd->double_quotes += 1;
	else
		return (-1);
	pos++;
	cmd->flag = 0;
	return (pos);
}

/**
 * @brief This function checks for any sp chars after the dollar token.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param i Iterator value set to position of prompt 
 * @return int Returns val of prompt position after sp chr.
 */
int	i_dollars(t_cmd	*cmd, char	*prompt, int pos)
{
	while (prompt[pos] != '\'' && prompt[pos] != '"' && prompt[pos] != ' '
		&& prompt[pos] != '|' && prompt[pos] != '>' && prompt[pos] != '\t'
		&& prompt[pos] != '<' && prompt[pos] != '\0')
				pos++;
	cmd->dollars += 1;
	return (pos);
}
