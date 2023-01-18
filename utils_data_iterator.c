/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data_iterator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:17:37 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/18 13:48:20 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	di_cwords(t_cmd	*args, char	*prompt, int	*pos)
{
	while (prompt[*pos + 1] != '\'' && prompt[*pos + 1] != '"'
			&& prompt[*pos + 1] != '|' && prompt[*pos + 1] != '>' 
				&& prompt[*pos + 1] != '<' && prompt[*pos + 1])
				(*pos)++;
	args->words += 1;
	if(prompt[*pos + 1])
		(*pos)++;
	return (0);
}

int	di_qwords(t_cmd	*args, char	*prompt, int	*pos)
{
	(*pos)++;
	while (prompt[*pos] != '\'' && prompt[*pos])
				(*pos)++;
	if(prompt[*pos] == '\'')
		args->quotes += 1;
	else
		return (-1);
	return (0);
}

int	di_dqwords(t_cmd	*args, char	*prompt, int	*pos)
{
	(*pos)++;
	while (prompt[*pos] != '"' && prompt[*pos])
				(*pos)++;
	if(prompt[*pos] == '"')
		args->double_quotes += 1;
	else
		return (-1);
	return (0);
}
