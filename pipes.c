/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/15 17:31:36 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fd(t_cmd	*cmd, t_env	*env, int	i)
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
		ft_child(cmd, env->env, fd, i);
	pid2 = fork();
	if (pid2 == 0)
		ft_adult (cmd, env->env, fd, i);
	waitpid (pid, NULL, 0);
	waitpid (pid2, NULL, 0);
	close(fd[0]);
	close(fd[1]);
	return ;
}

void	ft_pipes(t_cmd	*cmd, t_env	*env)
{
	int	i;

	i = -1;
	while(cmd->args[++i])
	{
		if(!ft_strncmp(cmd->args[i], "|", 1))
			ft_fd(cmd, env, i);
	}
}