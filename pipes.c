/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/21 16:31:21 by vzayas-s         ###   ########.fr       */
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
		ft_child(cmd->cmd, env->env, fd);
	else
	{
		waitpid (pid, NULL, 0);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return ;
}

/*  cmd->args -> buscar pipe
				Si pipe es encontrado -> hacer 2 veces la vuelta
				Si pipe no es encontrado -> hacer 1 vez la vuelta
				ls -l | wc -l | cat -e
*/

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
		printf("			POS -> %d\n", pos);
		while (cmd->args[pos])
		{
			pos++;
			ft_bid_free(cmd->cmd);
			cmd->cmd = ft_bid_strdup(cmd->atrb);
			ft_bid_free(cmd->atrb);
			i = 0;
			cmd->atrb = (char **)malloc(sizeof(char *)
					* (find_pipe(cmd->args, find_pipe(cmd->args, pos))) + 1);
			while (cmd->args[pos + i])
			{
				cmd->atrb[i] = ft_stephen_jokin(cmd, cmd->atrb[i], pos + i);
				i++;
			}
			cmd->atrb[i] = NULL;
			ft_fd(cmd, env);
			pos++;
			pos = find_pipe(cmd->args, pos);
		}
		exec(cmd->atrb, env->env);
	}
	else
		waitpid(pid, NULL, 0);
}
