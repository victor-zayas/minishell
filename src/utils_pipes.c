/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:14:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/27 16:36:31 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	atrb_fill(t_cmd	*cmd, int pipe_pos, int block_pos)
{
	while (cmd->args[++pipe_pos] && ft_strncmp(cmd->args[pipe_pos], "|", 1))
	{
		if (!ft_strncmp(cmd->args[pipe_pos], ">", 1)
			|| !ft_strncmp(cmd->args[pipe_pos], "<", 1))
		{
			cmd->redir_end = block_pos;
			if (cmd->args[pipe_pos])
				pipe_pos += 1;
		}
		else
			cmd->atrb[block_pos++] = ft_stephen_jokin(cmd, pipe_pos);
	}
	cmd->pipe_pos = pipe_pos;
	cmd->block_pos = block_pos;
}

int	ft_string_trader(t_cmd *cmd, int start)
{
	int	len;

	ft_doublefree(cmd->cmd);
	cmd->cmd = ft_doublestrdup(cmd->atrb);
	ft_doublefree(cmd->atrb);
	len = 0;
	while (cmd->args[start + len] && ft_strncmp(cmd->args[start + len], "|", 1)
		&& ft_strncmp(cmd->args[start + len], ">", 1)
		&& ft_strncmp(cmd->args[start + len], "<", 1))
		len += 1;
	cmd->atrb = (char **)malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (cmd->args[start + len]
		&& ft_strncmp(cmd->args[start + len], "|", 1)
		&& ft_strncmp(cmd->args[start + len], ">", 1)
		&& ft_strncmp(cmd->args[start + len], "<", 1))
	{
		cmd->atrb[len] = ft_stephen_jokin(cmd, start + len);
		len++;
	}
	cmd->atrb[len] = NULL;
	return (len);
}

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

int	find_sp(char **args, int i)
{
	int	len;

	len = 0;
	while (args[i])
	{
		if (!ft_strncmp(args[i], "|", 2) || !ft_strncmp(args[i], "||", 3))
			break ;
		else if (!ft_strncmp(args[i], ">", 2) || !ft_strncmp(args[i], "<", 2)
			|| !ft_strncmp(args[i], "<<", 3) || !ft_strncmp(args[i], ">>", 3))
		{
			if (args[i + 1])
				i++;
			else
				return (0); // expected arg for redir (0)
			len += 2;
		}
		i++;
	}
	if (args[i] && !ft_strncmp(args[i], "|", 2) && !args[i + 1])
		return (-1); // expected command (-1)
	return (i - len);
}
