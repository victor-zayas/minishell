/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:34:47 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/03 08:37:14 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_sig_exit;

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
