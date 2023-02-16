/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/16 20:27:39 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fd(t_cmd	*cmd, t_env	*env)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];

	if (pipe(fd) == -1)
		error ("pipe");
	pid = fork();
	if (pid < 0)
		error("fork");
	if (pid == 0)
		ft_child(cmd->cmd, env->env, fd);
	else {
		waitpid (pid, NULL, 0);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
	}
	pid2 = fork();
	if (pid2 == 0)
		ft_adult(cmd->atrb, env->env, fd);
	else
	{
		waitpid (pid2, NULL, 0);	
	}
	close(fd[0]);
	close(fd[1]);
	return ;
}
