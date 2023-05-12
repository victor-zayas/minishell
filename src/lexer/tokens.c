/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 11:57:32 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief [ft_lexer] fills the tokens we previously allocated
 * 			with the information of prompt.
 * 
 * @param args Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 * @param it Int set to zero to iterate through the loop.
 */
void	ft_lexer(t_cmd	*args, char	*prompt, int it)
{
	while (prompt[it])
	{
		while (prompt[it] == ' ' || prompt[it] == '\t')
			it++;
		if ((prompt[it] != '\'') && (prompt[it] != '"')
			&& (prompt[it] != '>') && (prompt[it] != '<')
			&& (prompt[it] != '|'))
				prompt = clean_words(args, prompt, it);
		else if ((prompt[it] == '\'') && prompt[it])
			prompt = quotes_lexer(args, prompt, it);
		else if (prompt[it] == '"' && prompt[it])
			prompt = double_quotes_lexer(args, prompt, it);
		else if (prompt[it] == '|' && prompt[it])
			prompt = one_lexer(args, prompt, it);
		else if (((prompt[it] == '<' && prompt[it + 1] == '<')
				|| (prompt[it] == '>'
					&& prompt[it + 1] == '>')) && prompt[it])
			prompt = two_lexer(args, prompt, it);
		else if ((prompt[it] == '<'
				|| prompt[it] == '>') && prompt[it])
			prompt = one_lexer(args, prompt, it);
		it = 0;
	}
	free(prompt);
}

/**
 * @brief Allocation of tokens, along with input & output arrays is made
 * 			by using the previously recollected data.
 * 		Tokens are filled with the content inside prompt.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param prompt String that we get from the CL.
 */
void	get_token(t_cmd	*cmd, char	*prompt)
{
	cmd->args = (char **)malloc(sizeof(char *) * (cmd->words + cmd->quotes
				+ cmd->double_quotes + cmd->pipes + cmd->out
				+ cmd->in + cmd->dollars + cmd->double_in
				+ cmd->double_out + 3));
	if (cmd->in || cmd->double_in)
		cmd->input = (int *)malloc(sizeof(int *)
				* (cmd->in + cmd->double_in + 1));
	if (cmd->out || cmd->double_out)
		cmd->output = (int *)malloc(sizeof(int *)
				* (cmd->out + cmd->double_out + 1));
	ft_lexer(cmd, prompt, 0);
	cmd->args[cmd->size] = NULL;
	cmd->size = 0;
}

// Structure and its compontents are freed
void	free_args(t_cmd	*args)
{
	int	i;

	i = 0;
	while (args->args[i])
		free(args->args[i++]);
	free(args->args);
	if (args->in || args->double_in)
		free(args->input);
	if (args->out || args->double_out)
		free(args->output);
}
