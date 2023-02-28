/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/28 16:06:12 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_fd(t_cmd	*cmd, t_env	*env)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error ("pipe");
	pid = fork();
	if (pid < 0)
		error("fork");
	if (pid == 0)
		ft_child(cmd, env, fd);
	else
	{
		waitpid (pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return ;
}

void	ft_pipe(t_cmd *cmd, t_env *env, int pos)
{
	pid_t	pid;
	int		i;

	i = -1;
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		ft_fd(cmd, env);
		while (cmd->args[pos])
		{
			pos++;
			cmd->cmd = ft_doublestrdup(cmd->atrb);
			ft_doublefree(cmd->atrb);
			i = 0;
			cmd->atrb = (char **)malloc(sizeof(char *)
					* (find_pipe(cmd->args, find_pipe(cmd->args, pos))) + 1);
			while (cmd->args[pos + i]
				&& ft_strncmp(cmd->args[pos + i], "|", 1))
			{
				cmd->atrb[i] = ft_stephen_jokin(cmd, pos + i);
				i++;
			}
			cmd->atrb[i] = NULL;
			ft_fd(cmd, env);
			pos = find_pipe(cmd->args, pos);
		}
		if (ft_builtings(cmd->atrb, cmd, env) == 1)
			exec(cmd->atrb, env->env);
		exit (1);
	}
	else
		waitpid(pid, NULL, 0);
}
