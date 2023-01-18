/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/18 12:52:57 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*clean_words(t_cmd	*cmd, char	*prompt, int	*pos)
{
	char *tmp;
	int	start;
	int	aux;

	aux = (*pos);
	start = (*pos);
	i_cwords(prompt, &aux);
	cmd->args[cmd->size++] = ft_substr(prompt, start, aux - start + 1);
	tmp = ft_substr(prompt, aux, ft_strlen(prompt) - aux + 1);
	if(prompt[aux + 1] != ' ' && prompt[aux + 1])
		*pos = 0;
	else
		*pos = 1;
	prompt = ft_strdup(tmp);
	free(tmp);
	return (prompt);
}

char	*quotes_lexer(t_cmd	*cmd, char	*prompt, int	*pos)
{
	char *tmp;
	int	start;
	int	aux;

	aux = (*pos);
	start = (*pos);
	i_qwords(prompt, &aux);
	cmd->args[cmd->size++] = ft_substr(prompt, start, aux - start + 1);
	tmp = ft_substr(prompt, aux, ft_strlen(prompt) - aux + 1);
	if(prompt[aux + 1] != ' ' && prompt[aux + 1])
		*pos = 0;
	else
		*pos = 1;
	prompt = ft_strdup(tmp);
	free(tmp);
	return (prompt);
}

char	*double_quotes_lexer(t_cmd	*cmd, char	*prompt, int	*pos)
{
	int	start;
	int	aux;
	char *tmp;

	aux = (*pos);
	start = (*pos);
	i_dqwords(prompt, &aux);
	cmd->args[cmd->size++] = ft_substr(prompt, start, aux - start + 1);
	tmp = ft_substr(prompt, aux, ft_strlen(prompt) - aux + 1);
	if(prompt[aux + 1] != ' ' && prompt[aux + 1])
		*pos = 0;
	else
		*pos = 1;
	prompt = ft_strdup(tmp);
	free(tmp);
	return (prompt);
}

char	*pipes_lexer(t_cmd	*cmd, char	*prompt, int	*pos)
{
	int		aux;
	char 	*tmp;

	aux = (*pos);
	cmd->args[cmd->size++] = ft_substr(prompt, aux, 1);
	tmp = ft_substr(prompt, aux, ft_strlen(prompt) - aux + 1);
	if(prompt[aux + 1] != ' ' && prompt[aux + 1])
		*pos = 0;
	else
		*pos = 1;
	prompt = ft_strdup(tmp);
	free(tmp);
	return (prompt);
}
