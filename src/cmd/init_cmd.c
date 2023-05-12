/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:06:25 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 12:37:15 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief	Error cases such as empty pipes, redirections or no commands
 * 			are handled in a correct way.
 * 
   @param cmd Structure holding data regarding tokens, cmds, ...
 * @return int Returns different values, depending error cases.
 */
int	ft_init_flags(t_cmd	*cmd)
{
	int		flag;
	pid_t	pid;

	flag = find_sp(cmd->args, 0);
	if (flag == -1)
		return (pipe_error(), 2);
	else if (flag == 0)
	{
		if (ft_redir(0, cmd->args, cmd) == -1)
			return (2);
		pid = fork();
		if (pid == 0)
		{
			open_fd(cmd);
			exit(0);
		}
		waitpid(pid, NULL, 0);
		return (1);
	}
	else
		cmd->cmd = (char **)malloc(sizeof(char *)
				* (find_sp(cmd->args, 0) + 1));
	return (0);
}

/**
 * @brief	Initializes the strings inside [cmd] structure for execution.
 * 			There are many cases involving errors and non-terminated expressions
 * 			that have been taking into account.
 * 
 * @param cmd Structure holding data regarding tokens, cmds, ...
 * @param env Structure holding enviroment, tokens, ...
 * @return int Returns the corresponding flag in cases any error happens.
 */
int	init_cmd(t_cmd	*cmd, t_env	*env)
{
	int	flag;

	flag = ft_init_flags(cmd);
	if (flag == 2)
		return (env->exit_value = 2, 2);
	else if (flag == 1)
		return (1);
	if (!cmd->args[find_pipe(cmd->args, 0)])
		return (0);
	if ((find_sp(cmd->args, (find_sp(cmd->args, 0) + 1) + 1))
		- (find_sp(cmd->args, 0) + 1) + 1 < 0)
		return (free(cmd->cmd), pipe_error(), env->exit_value = 2, 2);
	cmd->atrb = (char **)malloc(sizeof(char *)
			* (find_sp(cmd->args, (find_sp(cmd->args, 0) + 1) + 1))
			- (find_sp(cmd->args, 0) + 1) + 1);
	if (!cmd->atrb)
		return (ft_doublefree(cmd->cmd), 1);
	return (0);
}
