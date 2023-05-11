/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:18:09 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/11 06:49:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*one_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	int		aux;
	char	*tmp;

	aux = (pos);
	cmd->args[cmd->size++] = ft_substr(prompt, aux, 1);
	tmp = ft_substr(prompt, (aux + 1), ft_strlen(prompt) - aux + 1);
	free(prompt);
	return (tmp);
}

char	*two_lexer(t_cmd	*cmd, char	*prompt, int pos)
{
	int		aux;
	char	*tmp;

	aux = (pos + 1);
	cmd->args[cmd->size++] = ft_substr(prompt, pos, 2);
	tmp = ft_substr(prompt, (aux + 1), ft_strlen(prompt) - aux + 1);
	free(prompt);
	return (tmp);
}
