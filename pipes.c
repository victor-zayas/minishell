/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/29 18:07:49 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_adult(t_cmd *cmd, t_env *env, int pos)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	ft_fd(cmd, env, pos + 1);
	while (cmd->args[pos++])
	{
		i = ft_string_trader(cmd, pos);
		while (cmd->args[pos + i] && (!ft_strncmp(cmd->args[pos + i], ">", 1)
				|| !ft_strncmp(cmd->args[pos + i], "<", 1)))
		{
			ft_redir(pos + i, cmd->args, cmd, &check);
			i = i + 2;
		}
		ft_fd(cmd, env, pos + 1);
		pos = find_pipe(cmd->args, pos);
	}
}

void	ft_fd(t_cmd	*cmd, t_env	*env, int cmd_pos)
{
	pid_t	pid;
	int		fd[2];

	if (cmd->flag)
		cmd->cmd_start = cmd_pos;
	if (!cmd->flag)
		cmd->flag = 1;
	if (pipe(fd) == -1)
		error ("pipe");
	pid = fork();
	if (pid < 0)
		error("fork");
	if (pid == 0)
		ft_child(cmd, env, fd, cmd->cmd_start);
	else
	{
		waitpid (pid, NULL, 0);
		close(fd[1]);
		printf("xd\n");
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return ;
}

void	ft_pipe(t_cmd *cmd, t_env *env, int pos, int check)
{
	pid_t	pid;
	int		i;

	i = 0;
	cmd->cmd[pos] = NULL;
	while (cmd->args[++pos] && ft_strncmp(cmd->args[pos], "|", 1))
	{
		if (!ft_strncmp(cmd->args[pos], ">", 1)
			|| !ft_strncmp(cmd->args[pos], "<", 1))
		{
			i = check;
			ft_redir(pos, cmd->args, cmd, &check);
			check = i + 2;
			pos += 2;
			break ;
		}
		else
			cmd->atrb[check++] = ft_stephen_jokin(cmd, pos);
	}
	if (i)
		cmd->atrb[i] = NULL;
	else
		cmd->atrb[check] = NULL;
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		ft_adult(cmd, env, pos);
		//open_fd(cmd);
		if (ft_builtings(cmd->atrb, cmd, env, 0) == 1)
			exec(cmd->atrb, env); 
	}
	else
		waitpid(pid, NULL, 0);
	ft_doublefree(cmd->cmd);
	ft_doublefree(cmd->atrb);
}
