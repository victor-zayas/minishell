/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedgedog <hedgedog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:18:09 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/21 18:16:56 by hedgedog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*in_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	int		aux;
	char	*tmp;

	aux = (pos);
	cmd->args[cmd->size++] = ft_substr(prompt, aux, 1);
	tmp = ft_substr(prompt, (aux + 1), ft_strlen(prompt) - aux + 1);
	prompt = tmp;
	free(tmp);
	return (prompt);
}

char	*out_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	int		aux;
	char	*tmp;

	aux = (pos);
	cmd->args[cmd->size++] = ft_substr(prompt, aux, 1);
	tmp = ft_substr(prompt, (aux + 1), ft_strlen(prompt) - aux + 1);
	prompt = tmp;
	if (tmp)
		free(tmp);
	return (prompt);
}
