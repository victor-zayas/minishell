/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/30 14:34:14 by vzayas-s         ###   ########.fr       */
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
		for (int h = 0; cmd->cmd[h]; h++)
			printf("cmd-> [%s]\n", cmd->cmd[h]);
		for (int y = 0; cmd->atrb[y]; y++)
			printf("atrb-> [%s]\n", cmd->atrb[y]);
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
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
	return ;
}

void	ft_pipe(t_cmd *cmd, t_env *env, int pipe_pos, int block_pos)
{
	pid_t	pid;
	int		redir_end;

	redir_end = 0;
	close_str(cmd->cmd, pipe_pos, block_pos); // close leftmost command
	atrb_fill(cmd, pipe_pos, block_pos, redir_end);
	close_str(cmd->atrb, cmd->block_pos, cmd->redir_end);
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		ft_adult(cmd, env, cmd->pipe_pos);
		//open_fd(cmd);
		if (ft_builtings(cmd->atrb, cmd, env, 0) == 1)
			exec(cmd->atrb, env);
	}
	else
		waitpid(pid, NULL, 0);
	ft_doublefree(cmd->cmd);
	ft_doublefree(cmd->atrb);
}
