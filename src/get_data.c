/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:36 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/25 11:27:44 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if ((prompt[it] == '\'') && prompt[it])
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
