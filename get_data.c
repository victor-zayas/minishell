/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedgedog <hedgedog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:36 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/20 15:04:40 by hedgedog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_data(t_cmd	*args, char	*prompt)
{
	int	i;

	i = 0;
	while(prompt[i])
	{
		while(prompt[i] == ' ' && prompt[i])
			i++;
		if((prompt[i] != '\'') && (prompt[i] != '"') &&
				(prompt[i] != '>')  && (prompt[i] != '<') 
					&& (prompt[i] != '|') && prompt[i])
			i = i_cwords(args, prompt, i);
		if((prompt[i] == '\'') && prompt[i])
			i = i_qwords(args, prompt, i);
		if (prompt[i] == '"' && prompt[i])
			i = i_dqwords(args, prompt, i);
		if (prompt[i] == '|' && prompt[i])
		{
			args->pipes += 1;
			i++;
		}
		if (prompt[i] == '<' && prompt[i])
		{
			args->lesser += 1;
			i++;
		}
		if (prompt[i] == '>' && prompt[i])
		{
			args->greater += 1;
			i++;
		}
	}
}
