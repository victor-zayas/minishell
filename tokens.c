/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/27 15:43:07 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_cmd *cmd, t_env *env, char	**envp, int *stdio)
{
	env->env = ft_env_strdup(envp);
	env->oldpwd = NULL;
	env->exit_value = 0;
	signal(SIGINT, my_signal);
	signal(SIGQUIT, SIG_IGN);
	init_args(cmd);
	getstdio(stdio);
}

void	init_args(t_cmd *cmd)
{
	cmd->size = 0;
	cmd->words = 0;
	cmd->quotes = 0;
	cmd->double_quotes = 0;
	cmd->pipes = 0;
	cmd->out = 0;
	cmd->in = 0;
	cmd->dollars = 0;
	cmd->double_in = 0;
	cmd->double_out = 0;
	cmd->flag = 0;
	cmd->in_it = 0;
	cmd->out_it = 0;
	cmd->i.i1 = 0;
	cmd->i.i2 = 0;
	cmd->i.i3 = 0;
	cmd->i.i4 = 0;
	cmd->i.i5 = 0;
}

void	ft_lexer(t_cmd	*args, char	*prompt)
{
	while (prompt[args->i.i2])
	{
		while (prompt[args->i.i2] == ' ' || prompt[args->i.i2] == '\t')
			args->i.i2++;
		if ((prompt[args->i.i2] != '\'') && (prompt[args->i.i2] != '"')
			&& (prompt[args->i.i2] != '>') && (prompt[args->i.i2] != '<')
			&& (prompt[args->i.i2] != '|'))
				prompt = clean_words(args, prompt, args->i.i2);
		else if ((prompt[args->i.i2] == '\'') && prompt[args->i.i2])
			prompt = quotes_lexer(args, prompt, args->i.i2);
		else if (prompt[args->i.i2] == '"' && prompt[args->i.i2])
			prompt = double_quotes_lexer(args, prompt, args->i.i2);
		else if (prompt[args->i.i2] == '|' && prompt[args->i.i2])
			prompt = one_lexer(args, prompt, args->i.i2);
		else if (((prompt[args->i.i2] == '<' && prompt[args->i.i2 + 1] == '<')
				|| (prompt[args->i.i2] == '>'
					&& prompt[args->i.i2 + 1] == '>')) && prompt[args->i.i2])
			prompt = two_lexer(args, prompt, args->i.i2);
		else if ((prompt[args->i.i2] == '<'
				|| prompt[args->i.i2] == '>') && prompt[args->i.i2])
			prompt = one_lexer(args, prompt, args->i.i2);
		args->i.i2 = 0;
	}
	free(prompt);
}

void	get_token(t_cmd	*cmd, char	*prompt)
{
	cmd->args = (char **)malloc(sizeof(char *) * (cmd->words + cmd->quotes
				+ cmd->double_quotes + cmd->pipes + cmd->out
				+ cmd->in + cmd->dollars + cmd->double_in
				+ cmd->double_out + 1));
	if (cmd->in || cmd->double_in)
		cmd->input = (int *)malloc(sizeof(int *)
				* (cmd->in + cmd->double_in + 1));
	if (cmd->out || cmd->double_out)
		cmd->output = (int *)malloc(sizeof(int *)
				* (cmd->out + cmd->double_out + 1));
	ft_lexer(cmd, prompt);
	cmd->args[cmd->size] = NULL;
	cmd->size = 0;
}

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
