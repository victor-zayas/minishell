/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/30 11:31:18 by jaizpuru         ###   ########.fr       */
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

void	ft_pipe(t_cmd *cmd, t_env *env, int pos, int check)
{
	pid_t	pid;
	int		i;

	i = 0;
	close_str(cmd->cmd, pos, check); // close leftmost command

	while (cmd->args[++pos] && ft_strncmp(cmd->args[pos], "|", 1)) //fill the next command
	{
		if (!ft_strncmp(cmd->args[pos], ">", 1) // if redirection is found
			|| !ft_strncmp(cmd->args[pos], "<", 1))
		{
			i = check; // we grab with i the value of string termination
			if (cmd->args[pos])
				pos++;
		}
		else
			cmd->atrb[check++] = ft_stephen_jokin(cmd, pos);
	}
	close_str(cmd->atrb, check, i);
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
