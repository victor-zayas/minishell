/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:36 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/08 18:25:29 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_data(t_cmd	*args, char	*prompt)
{
	while (prompt[args->i.i1] && args->i.i1 >= 0)
	{
		while (prompt[args->i.i1] == ' ' || prompt[args->i.i1] == '\t')
			args->i.i1++;
		if ((prompt[args->i.i1] != '\'') && (prompt[args->i.i1] != '"')
			&& (prompt[args->i.i1] != '>') && (prompt[args->i.i1] != '<')
			&& (prompt[args->i.i1] != '|') && (prompt[args->i.i1] != '$')
			&& prompt[args->i.i1])
			args->i.i1 = i_cwords(args, prompt, args->i.i1);
		if ((prompt[args->i.i1] == '\'') && prompt[args->i.i1])
			args->i.i1 = i_qwords(args, prompt, args->i.i1);
		if (prompt[args->i.i1] == '"' && prompt[args->i.i1])
			args->i.i1 = i_dqwords(args, prompt, args->i.i1);
		if (prompt[args->i.i1] == '|' && prompt[args->i.i1])
			args->i.i1 = i_sp(args, prompt, args->i.i1);
		if (prompt[args->i.i1] == '<' && prompt[args->i.i1])
			args->i.i1 = i_sp(args, prompt, args->i.i1);
		if (prompt[args->i.i1] == '>' && prompt[args->i.i1])
			args->i.i1 = i_sp(args, prompt, args->i.i1);
		if (prompt[args->i.i1] == '$' && prompt[args->i.i1])
			args->i.i1 = i_dollars(args, prompt, args->i.i1);
	}
	return (args->i.i1);
}

int	i_sp(t_cmd	*cmd, char	*prompt, int i)
{
	if (prompt[i] == '|')
		cmd->pipes += 1;
	else if (prompt[i] == '>' && prompt[i + 1] && prompt[i + 1] == '>')
	{
		cmd->double_redir += 1;
		return (i + 2);
	}
	else if (prompt[i] == '<' && prompt[i + 1] && prompt[i + 1] == '<')
	{
		cmd->double_redir += 1;
		return (i + 2);
	}
	else if (prompt[i] == '>')
		cmd->lesser += 1;
	else if (prompt[i] == '<')
		cmd->greater += 1;
	return (i + 1);
}
