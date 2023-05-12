/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:14:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 10:24:29 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_child(t_cmd	*cmd, t_env	*env, int	*fd, int cmd_start)
{
	pid_t	pid;
	int		rt;

	close(fd[0]);
	if (cmd->args[cmd_start] && !ft_check_redir(cmd->args, cmd_start))
		dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (*cmd->cmd && ft_builtings(cmd->cmd, cmd, env, 0) == 1)
	{
		pid = fork();
		if (pid == 0)
			exec(cmd->cmd, env);
		waitpid(pid, &rt, 0);
	}
	exit (WEXITSTATUS(rt));
}

int	find_pipe(char **args, int i)
{
	while (args[i])
	{
		if (!ft_strncmp(args[i], "|", 2))
			break ;
		i++;
	}
	return (i);
}
