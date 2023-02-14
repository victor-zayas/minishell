/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:36 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/14 18:10:44 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_data(t_cmd	*args, char	*prompt)
{
	int	i;

	i = 0;
	while (prompt[i])
	{
		while (prompt[i] == ' ' || prompt[i] == '\t')
			i++;
		if ((prompt[i] != '\'') && (prompt[i] != '"')
			&& (prompt[i] != '>') && (prompt[i] != '<')
			&& (prompt[i] != '|') && (prompt[i] != '$')
			&& prompt[i])
			i = i_cwords(args, prompt, i);
		if ((prompt[i] == '\'') && prompt[i])
			i = i_qwords(args, prompt, i);
		if (prompt[i] == '"' && prompt[i])
			i = i_dqwords(args, prompt, i);
		if (prompt[i] == '|' && prompt[i])
			i = i_pipes(args, i);
		if (prompt[i] == '<' && prompt[i])
			i = i_pipes(args, i);
		if (prompt[i] == '>' && prompt[i])
			i = i_pipes(args, i);
		if (prompt[i] == '$' && prompt[i])
			i = i_dollars(args, prompt, i);
	}
}

int	i_pipes(t_cmd	*cmd, int i)
{
	cmd->pipes += 1;
	return (i + 1);
}

int	i_in(t_cmd	*cmd, int i)
{
	cmd->lesser += 1;
	return (i + 1);
}

int	i_out(t_cmd	*cmd, int i)
{
	cmd->greater += 1;
	return (i + 1);
}
