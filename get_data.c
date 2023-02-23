/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:36 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/23 20:03:36 by jaizpuru         ###   ########.fr       */
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
			i = i_sp(args, prompt, i);
		if (prompt[i] == '<' && prompt[i])
			i = i_sp(args, prompt, i);
		if (prompt[i] == '>' && prompt[i])
			i = i_sp(args, prompt, i);
		if (prompt[i] == '$' && prompt[i])
			i = i_dollars(args, prompt, i);
	}
}

int	i_sp(t_cmd	*cmd, char	*prompt, int i)
{
	cmd->pipes += 1;
	if (prompt[i] == '|')
		cmd->pipes += 1;
	return (i + 1);
}
