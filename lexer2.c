/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:18:09 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/17 13:06:54 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*in_lexer(t_cmd	*cmd, char	*prompt, int	*pos)
{
	int		aux;
	char 	*tmp;

	aux = (*pos);
	cmd->args[cmd->size++] = ft_substr(prompt, aux, 2);
	tmp = ft_substr(prompt, aux, ft_strlen(prompt) - aux + 1);
	if(prompt[aux + 1] != ' ')
		*pos = 0;
	else
		*pos = 1;
	return (prompt);
}

char	*out_lexer(t_cmd	*cmd, char	*prompt, int	*pos)
{
	int		aux;
	char 	*tmp;

	aux = (*pos);
	cmd->args[cmd->size++] = ft_substr(prompt, aux, 1);
	tmp = ft_substr(prompt, aux, ft_strlen(prompt) - aux + 1);
	if(prompt[aux + 1] != ' ')
		*pos = 0;
	else
		*pos = 1;
	return (prompt);
}