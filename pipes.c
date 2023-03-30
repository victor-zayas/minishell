/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/30 23:45:36 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_adult(t_cmd *cmd, t_env *env, int pos)
{
	int	i;

	i = 0;
	ft_fd(cmd, env, pos);
	while (cmd->args[pos++])
	{
		i = ft_string_trader(cmd, pos);
		while (cmd->args[pos + i] && (!ft_strncmp(cmd->args[pos + i], ">", 1)
				|| !ft_strncmp(cmd->args[pos + i], "<", 1)))
			i = i + 2;
		if (!ft_strncmp(cmd->args[pos - 1], "|", 1) && cmd->args[pos] == NULL)
		{
			ft_doublefree(cmd->cmd);
			cmd->flag = -1;
			return ;
		}
		ft_fd(cmd, env, pos);
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
	int		block_pos2;
	int		redir_end;

	redir_end = 0;
	block_pos2 = 0;
	cmd->flag = 0;
	close_str(cmd->cmd, pipe_pos, block_pos);
	if (!ft_strncmp(cmd->args[pipe_pos], "|", 1) && cmd->args[pipe_pos + 1] == NULL)
	{
		ft_doublefree(cmd->cmd);
		free(cmd->atrb);
		return ;
	}
	atrb_fill(cmd, pipe_pos, block_pos2, redir_end);
	close_str(cmd->atrb, cmd->block_pos, cmd->redir_end);
	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		ft_adult(cmd, env, cmd->pipe_pos);
		if (cmd->flag == -1)
			exit (139);
		if (ft_builtings(cmd->atrb, cmd, env, 0) == 1)
			exec(cmd->atrb, env);
	}
	else
		waitpid(pid, NULL, 0);
	ft_doublefree(cmd->cmd);
	ft_doublefree(cmd->atrb);
}
