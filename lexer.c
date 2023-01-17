/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:16:59 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/17 18:39:36 by jaizpuru         ###   ########.fr       */
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
	aux++;
	while (prompt[aux + 1] != '\'' && prompt[aux + 1] != '"'
			&& prompt[aux + 1] != '|' && prompt[aux] != '>' 
				&& prompt[aux] != '<' && prompt[aux + 1])
				aux++;
	cmd->args[cmd->size++] = ft_substr(prompt, start, aux - start + 1);
	tmp = ft_substr(prompt, aux, ft_strlen(prompt) - aux + 1);
	tmp = ft_strdup(tmp);
	prompt = tmp;
	free(tmp);
	*pos = 0;
	return (prompt);
}

char	*quotes_lexer(t_cmd	*cmd, char	*prompt, int	*pos)
{
	char *tmp;
	int	start;
	int	aux;
	int	checker;

	checker = 1;
	aux = (*pos);
	start = (*pos);
	aux++;
	while (prompt[aux] != '\'' && prompt[aux])
				aux++;
	cmd->args[cmd->size++] = ft_substr(prompt, start, aux - start + 1);
	printf("				ARG->> %s\n", cmd->args[cmd->size - 1]);
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

	aux = (*pos);
	start = (*pos);
	aux++;
	while (prompt[aux] != '"' && prompt[aux])
				aux++;
	cmd->args[cmd->size++] = ft_substr(prompt, start, aux - start + 1);
	char *tmp = ft_substr(prompt, aux, ft_strlen(prompt) - aux + 1);
	prompt = ft_strdup(tmp);
	free(tmp);
	if(prompt[aux + 1] != ' ' && prompt[aux + 1])
		*pos = 0;
	else
		*pos = 1;
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
	return (prompt);
}
