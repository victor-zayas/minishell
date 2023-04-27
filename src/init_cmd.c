/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:06:25 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/27 22:07:50 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_init_flags(t_cmd	*cmd)
{
	int		flag;
	pid_t	pid;

	flag = find_sp(cmd->args, 0); // find in args until [redir] or [pipe]
	if (flag == -1) // [pipe_error] case
		return (2);
	else if (flag == 0) // [heredoc] case
	{
		ft_redir(0, cmd->args, cmd);
		pid = fork();
		if (pid == 0) // heredoc needs a personal fork
		{
			open_fd(cmd); // open [heredoc]
			exit(0);
		}
		waitpid(pid, NULL, 0);
		return (1); // return val for [heredoc]
	}
	else
		cmd->cmd = (char **)malloc(sizeof(char *)
				* (flag + 1)); // allocate mem for [cmd->cmd]
	return (0);
}

int	init_cmd(t_cmd	*cmd, t_env	*env)
{
	int	flag;
	int	atrb_size;

	flag = ft_init_flags(cmd);
	if (flag == 2) // [pipe_error] case
		return (pipe_error(cmd, env), 1);
	else if (flag == 1) // heredoc case
		return (1);
	if (!cmd->args[find_pipe(cmd->args, 0)]) // if no pipe found on args
		return (0);
	flag = find_sp(cmd->args, 0);
	atrb_size = (find_sp(cmd->args, (flag + 1))) - (flag + 1);
	cmd->atrb = (char **)malloc(sizeof(char *) * (atrb_size + 1));
	if (!cmd->atrb)
		return (ft_doublefree(cmd->cmd), 1);
	return (0);
}
