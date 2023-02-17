/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/17 16:05:07 by jaizpuru         ###   ########.fr       */
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

void    ft_pipe(t_cmd   *cmd, t_env *env, int __unused pos)
{
    pid_t   pid;
	int		i;

/*  cmd->args -> buscar pipe
                Si pipe es encontrado -> hacer 2 veces la vuelta
                Si pipe no es encontrado -> hacer 1 vez la vuelta
                ls -l | wc -l | cat -e
                 */
    i = -1;
	pid = fork();
    if (pid < 0)
        perror("Error");
    if (pid == 0)
    {
        ft_fd(cmd, env);
        //printf("              POS1 -> %d\n", find_pipe(cmd->args, pos));
    	pos = find_pipe(cmd->args, pos);
        while(cmd->args[find_pipe(cmd->args, pos)])
        {
			ft_bid_free(cmd->cmd);
			cmd->cmd = ft_bid_strdup(cmd->atrb);
			ft_bid_free(cmd->atrb);
			while (cmd->args[find_pipe(cmd->args, pos) + 1])
			{
				cmd->atrb[i] = ft_stephen_jokin(cmd, cmd->atrb[i], pos);
				pos++;
			}
			ft_fd(cmd, env);
            pos++;
            pos = find_pipe(cmd->args, pos);
            printf("                POS2 -> %d\n", pos);
        }
        exec(cmd->atrb, env->env);
    }
    else
        waitpid(pid, NULL, 0);
}
