/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iterator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:10:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/27 17:27:04 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	i_cwords(t_cmd	*cmd, char	*prompt, int pos)
{
	while (prompt[pos] != '\'' && prompt[pos] != '"' && prompt[pos] != ' '
		&& prompt[pos] != '|' && prompt[pos] != '>' && prompt[pos] != '\t'
		&& prompt[pos] != '<' && prompt[pos] != '$' && prompt[pos] != '\0')
				pos++;
	cmd->words += 1;
	return (pos);
}

int	i_qwords(t_cmd	*cmd, char	*prompt, int pos)
{
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

int	i_dqwords(t_cmd	*cmd, char	*prompt, int pos)
{
	cmd->flag = 1;
	while (prompt[++pos] != '"' && prompt[pos])
	{
		if (prompt[pos] == '$')
		{
			if (cmd->flag == 0)
				cmd->dollars++;
			else
				cmd->flag = 0;
		}
	}
	if (prompt[pos] == '"')
		cmd->double_quotes += 1;
	else
		return (-1);
	pos++;
	cmd->flag = 0;
	return (pos);
}

int	i_dollars(t_cmd	*cmd, char	*prompt, int pos)
{
	while (prompt[pos] != '\'' && prompt[pos] != '"' && prompt[pos] != ' '
		&& prompt[pos] != '|' && prompt[pos] != '>' && prompt[pos] != '\t'
		&& prompt[pos] != '<' && prompt[pos] != '\0')
				pos++;
	cmd->dollars += 1;
	return (pos);
}
