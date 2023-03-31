/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:14:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/31 11:46:10 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	atrb_fill(t_cmd	*cmd, int pipe_pos, int block_pos, int redir_end)
{
	while (cmd->args[++pipe_pos] && ft_strncmp(cmd->args[pipe_pos], "|", 1)) //fill the next command
	{
		if (!ft_strncmp(cmd->args[pipe_pos], ">", 1) // if redirection is found
			|| !ft_strncmp(cmd->args[pipe_pos], "<", 1))
		{
			redir_end = block_pos; // we grab with i the value of string termination
			if (cmd->args[pipe_pos])
				pipe_pos += 1;
		}
		else
			cmd->atrb[block_pos++] = ft_stephen_jokin(cmd, pipe_pos);
	}
	cmd->pipe_pos = pipe_pos;
	cmd->block_pos = block_pos;
	cmd->redir_end = redir_end;
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
		len++;
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
		rt = WEXITSTATUS(rt);
		env->exit_value = rt;
	}
	exit (1);
}

int	find_pipe(char **args, int i)
{
	while (args[i])
	{
		if (ft_strchr(args[i], '|'))
			break ;
		i++;
	}
	return (i);
}

int	find_sp(char **args, int i)
{
	while (args[i])
	{
		if (ft_strchr(args[i], '|') || ft_strchr(args[i], '>')
			|| ft_strchr(args[i], '<'))
			break ;
		i++;
	}
	return (i);
}
