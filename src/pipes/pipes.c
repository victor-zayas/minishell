/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 10:25:41 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_get_pipes(t_cmd *cmd, t_env *env, int pos)
{
	int	i;

	i = 0;
	ft_adult(cmd, env, 0);
	while (cmd->args[pos + 1] && cmd->args[pos++])
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
		cmd->i.i5 = find_pipe(cmd->args, cmd->i.i5);
		ft_adult(cmd, env, ++cmd->i.i5);
		pos = find_pipe(cmd->args, pos);
	}
}

void	adult_wait(int fd[2], t_env	*env, pid_t	pid, char	*str)
{
	waitpid (pid, &env->exit_value, 0);
	env->exit_value = WEXITSTATUS(env->exit_value);
	close(fd[1]);
	if (!ft_checker(str))
		close(fd[0]);
	else
		dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
}

void	ft_adult(t_cmd	*cmd, t_env	*env, int cmd_pos)
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
		adult_wait(fd, env, pid, *cmd->atrb);
	return ;
}

void	ft_index_piper(t_cmd	*cmd, t_env	*env)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		ft_get_pipes(cmd, env, cmd->pipe_pos);
		if (cmd->flag == -1)
			exit (130);
		cmd->i.i5 = get_last_redir(cmd->args, 0);
		if (cmd->i.i5 == -1)
			exit (2);
		if (cmd->i.i5)
			ft_check_redir(cmd->args, cmd->i.i5);
		if (ft_builtings(cmd->atrb, cmd, env, 0) == 1)
			exec(cmd->atrb, env);
		exit (1);
	}
	else
		waitpid(pid, &cmd->flag, 0);
	env->exit_value = WEXITSTATUS(cmd->flag);
}

void	ft_pipe(t_cmd *cmd, t_env *env, int pipe_end, int sp_end)
{
	cmd->flag = 0;
	init_cmd_pipes(cmd, pipe_end, sp_end);
	ft_index_piper(cmd, env);
	ft_doublefree(cmd->cmd);
	ft_doublefree(cmd->atrb);
}
