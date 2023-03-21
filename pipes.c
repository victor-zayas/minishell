/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:08:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/21 19:48:31 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_adult(t_cmd	*cmd, t_env	*env, int pos)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	ft_fd(cmd, env);
	while (cmd->args[pos])
	{
		pos++;
		ft_doublefree(cmd->cmd);
		cmd->cmd = ft_doublestrdup(cmd->atrb);
		ft_doublefree(cmd->atrb);
		i = 0;
		while(cmd->args[pos + i] && ft_strncmp(cmd->args[pos + i], "|", 1))
			i++;
		cmd->atrb = (char **)malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (cmd->args[pos + i]
			&& ft_strncmp(cmd->args[pos + i], "|", 1))
		{
			printf("cmd inside pipe -> [%s]\n", cmd->args[pos + i]);
			cmd->atrb[i] = ft_stephen_jokin(cmd, pos + i);
			i++;
		}
		if (check)
			cmd->atrb[check] = NULL;
		else
			cmd->atrb[i] = NULL;
		ft_fd(cmd, env);
		pos = find_pipe(cmd->args, pos);
	}
}

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

void	ft_pipe(t_cmd *cmd, t_env *env, int pos, int check)
{
	pid_t	pid;

	pid = fork();
	cmd->cmd[pos] = NULL;
	while (cmd->args[++pos] && ft_strncmp(cmd->args[pos], "|", 1))
		cmd->atrb[check++] = ft_stephen_jokin(cmd, pos);
	cmd->atrb[check] = NULL;
	if (pid < 0)
		perror("Error");
	if (pid == 0)
	{
		ft_adult(cmd, env, pos);
		if (ft_builtings(cmd->atrb, cmd, env) == 1)
			exec(cmd, cmd->atrb, env);
		ft_doublefree(cmd->atrb);
		exit (1);
	}
	else
		waitpid(pid, NULL, 0);
	ft_doublefree(cmd->atrb);
	ft_doublefree(cmd->cmd);
}
