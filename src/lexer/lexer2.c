/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:18:09 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 12:09:45 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief	Cuts a one sized sp-character as a token and shortens
 * 			the returned prompt with the same one.
 * 
 * 			Used for pipes[|] and simple redir [>][<].
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param pos Position of the current chr inside prompt.
 * @return char* The same prompt without sp-char is returned.
 */
char	*one_lexer(t_cmd *cmd, char	*prompt, int pos)
{
	int		aux;
	char	*tmp;

	aux = (pos);
	cmd->args[cmd->size++] = ft_substr(prompt, aux, 1);
	tmp = ft_substr(prompt, (aux + 1), ft_strlen(prompt) - aux + 1);
	free(prompt);
	return (tmp);
}

/**
 * @brief	Cuts a two-sized sp-character as a token and shortens
 * 			the returned prompt with the same one.
 * 
 * 			Used for double-redir [>>][<<].
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param pos Position of the current chr inside prompt.
 * @return char* The same prompt without sp-char is returned.
 */
char	*two_lexer(t_cmd *cmd, char *prompt, int pos)
{
	int		aux;
	char	*tmp;

	aux = (pos + 1);
	cmd->args[cmd->size++] = ft_substr(prompt, pos, 2);
	tmp = ft_substr(prompt, (aux + 1), ft_strlen(prompt) - aux + 1);
	free(prompt);
	return (tmp);
}
