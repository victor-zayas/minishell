/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/08 15:11:21 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_cmd *cmd, t_env *env, char	**envp)
{
	env->env = ft_env_strdup(envp);
	env->oldpwd = NULL;
	signal(SIGINT, my_signal);
	signal(SIGQUIT, SIG_IGN);
	cmd->size = 0;
	cmd->words = 0;
	cmd->quotes = 0;
	cmd->double_quotes = 0;
	cmd->pipes = 0;
	cmd->lesser = 0;
	cmd->greater = 0;
	cmd->dollars = 0;
	cmd->double_redir = 0;
	cmd->flag = 0;
	cmd->input = 0;
	cmd->output = 1;
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
				+ cmd->double_quotes + cmd->pipes + cmd->lesser
				+ cmd->greater + cmd->dollars + cmd->double_redir + 1));
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
}
