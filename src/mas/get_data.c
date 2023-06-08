/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:36 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/06/08 10:43:30 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Function that clasifies characters from the prompt
 * 			in order to know how many bytes we need to allocate.
 * 
 * @param args Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param it Int set to zero to iterate through the loop.
 * @return int Returns (-1) when error, else (counted chrs of prompt).
 */

int	get_data(t_cmd	*args, char	*prompt, int it)
{
	while (it != -1 && prompt[it])
	{
		while (prompt[it] == ' ' || prompt[it] == '\t')
			it++;
		if ((prompt[it] != '\'') && (prompt[it] != '"')
			&& (prompt[it] != '>') && (prompt[it] != '<')
			&& (prompt[it] != '|') && (prompt[it] != '$')
			&& prompt[it])
			it = i_cwords(args, prompt, it);
		if (it != -1 && (prompt[it] == '\'') && prompt[it])
			it = i_qwords(args, prompt, it);
		if (it != -1 && prompt[it] == '"' && prompt[it])
			it = i_dqwords(args, prompt, it);
		if (it != -1 && prompt[it] == '|' && prompt[it])
			it = i_sp(args, prompt, it);
		if (it != -1 && prompt[it] == '<' && prompt[it])
			it = i_sp(args, prompt, it);
		if (it != -1 && prompt[it] == '>' && prompt[it])
			it = i_sp(args, prompt, it);
		if (it != -1 && prompt[it] == '$' && prompt[it])
			it = i_dollars(args, prompt, it);
	}
	return (it);
}

/**
 * @brief This function collects information about what sp chars
 * 			have been found and keeps the number inside cmd structure.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param i Iterator value set to position of prompt 
 * @return int Returns val of prompt position after sp chr.
 */
int	i_sp(t_cmd	*cmd, char	*prompt, int i)
{
	if (prompt[i] == '|')
		cmd->pipes += 1;
	else if (prompt[i] == '>' && prompt[i + 1] && prompt[i + 1] == '>')
	{
		cmd->double_out += 1;
		return (i + 2);
	}
	else if (prompt[i] == '<' && prompt[i + 1] && prompt[i + 1] == '<')
	{
		cmd->double_in += 1;
		return (i + 2);
	}
	else if (prompt[i] == '>')
		cmd->out += 1;
	else if (prompt[i] == '<')
		cmd->in += 1;
	return (i + 1);
}
