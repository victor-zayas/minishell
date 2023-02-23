/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iterator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:10:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/23 20:03:16 by jaizpuru         ###   ########.fr       */
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
		exit (EXIT_FAILURE);
	pos++;
	return (pos);
}

int	i_dqwords(t_cmd	*cmd, char	*prompt, int pos)
{
	(pos)++;
	while (prompt[pos] != '"' && prompt[pos])
				pos++;
	if (prompt[pos] == '"')
		cmd->double_quotes += 1;
	else
		exit (EXIT_FAILURE);
	pos++;
	return (pos);
}

int	i_dollars(t_cmd	*cmd, char	*prompt, int pos)
{
	if (prompt[pos + 1] && prompt[pos + 1] != ' ')
		pos++;
	while (prompt[pos] != '\'' && prompt[pos] != '"' && prompt[pos] != ' '
		&& prompt[pos] != '|' && prompt[pos] != '>' && prompt[pos] != '\t'
		&& prompt[pos] != '<' && prompt[pos] != '\0')
				pos++;
	if (prompt[pos] && prompt[pos] != ' ')
	{
		if (prompt[pos - 2] == ' ' && prompt[pos - 1] == '\0')
			return (pos);
	}
	else
		cmd->dollars += 1;
	return (pos);
}
