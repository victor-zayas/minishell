/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_iterator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:10:57 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/18 12:53:11 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	i_cwords(char	*prompt, int	*pos)
{
	while (prompt[*pos + 1] != '\'' && prompt[*pos + 1] != '"'
			&& prompt[*pos + 1] != '|' && prompt[*pos + 1] != '>' 
				&& prompt[*pos + 1] != '<' && prompt[*pos + 1])
				(*pos)++;
}

void	i_qwords(char	*prompt, int	*pos)
{
	(*pos)++;
	while (prompt[*pos] != '\'' && prompt[*pos])
				(*pos)++;
}

void	i_dqwords(char	*prompt, int	*pos)
{
	(*pos)++;
	while (prompt[(*pos)] != '"' && prompt[(*pos)])
				(*pos)++;
}
