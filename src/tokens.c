/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/27 12:31:22 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_sig_exit;

void	init_shell(t_cmd *cmd, t_env *env, char	**envp, int *stdio)
{
	env->env = ft_env_strdup(envp);
	ft_unset(env, "OLDPWD");
	env->oldpwd = NULL;
	env->exit_value = 0;
	signal(SIGINT, my_signal);
	if (g_sig_exit)
		env->exit_value = g_sig_exit;
	signal(SIGQUIT, SIG_IGN);
	init_args(cmd);
	getstdio(stdio);
}

void	init_args(t_cmd *cmd)
{
	cmd = ft_memset(cmd, 0, sizeof(t_cmd));
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
	cmd->cmd_start = 0;
	cmd->pipe_pos = 0;
	cmd->block_pos = 0;
	cmd->redir_end = 0;
	cmd->i.i1 = 0;
	cmd->i.i2 = 0;
	cmd->i.i3 = 0;
	cmd->i.i4 = 0;
	cmd->i.i5 = 0;
}

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
