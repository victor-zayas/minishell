/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:30:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/06 17:46:47 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd(t_cmd	*cmd)
{
	cmd->cmd = (char **)malloc(sizeof(char *) * (find_pipe(cmd->args, 0) + 1));
	if (!cmd->cmd)
		return ;
	if (!cmd->args[find_pipe(cmd->args, (find_pipe(cmd->args, 0)))])
	{
		cmd->flag = 1;
		return ;
	}
	cmd->atrb = (char **)malloc(sizeof(char *)
			* (find_pipe(cmd->args, (find_pipe(cmd->args, 0) + 1)) + 1));
	if (!cmd->atrb)
		return ;
}

void	exec_cmd(char	**cmd, char	**enviroment)
{
	char	**path;
	char	*aux;
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (!cmd)
			return ;
		i = 0;
		aux = ft_path(enviroment);
		if (!aux)
		{
			if (execve(*cmd, cmd, NULL) == -1)
				exit(error_code(*cmd));
			exit(error_code(*cmd));
		}
		path = ft_split(aux, ':');
		free (aux);
		while (path[i] != NULL)
		{
			aux = ft_strjoin(path[i], "/");
			if (access(*cmd, X_OK) == 0)
			{
				free(aux);
				aux = ft_strdup(*cmd);
				break ;
			}
			else
			{
				free (path[i]);
				path[i] = ft_strjoin(aux, *cmd);
			}
			free (aux);
			aux = ft_strdup(path[i++]);
			if (access(aux, X_OK) == 0)
				break ;
			free (aux);
		}
		if (aux && path[i] && !access(aux, X_OK))
			execve(aux, cmd, enviroment);
		exit (error_code(*cmd));
	}
	wait(&i);
	//printf("exit value -> %d\n", WEXITSTATUS(i));
	return ;
}

char	*ft_stephen_jokin(t_cmd *cmd, int i)
{
	char	*aux;

	aux = ft_strdup(cmd->args[i]);
	return (aux);
}

void	ft_selector(t_cmd *cmd, t_env *env)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	init_cmd(cmd);
	while (cmd->args[++i])
	{
		if (!ft_strncmp(cmd->args[i], "|", 1) && i > 0)
		{
			cmd->cmd[i] = NULL;
			while (cmd->args[++i] && ft_strncmp(cmd->args[i], "|", 1))
			{
				cmd->atrb[j] = ft_stephen_jokin(cmd, i);
				j++;
			}
			cmd->atrb[j] = NULL;
			ft_pipe(cmd, env, i);
			ft_doublefree(cmd->atrb);
			ft_doublefree(cmd->cmd);
			return ;
		}
		else if (!ft_strncmp(cmd->args[i], ">", 1)
			|| !ft_strncmp(cmd->args[i], "<", 1))
		{
			if (!cmd->args[i + 1])
				return ;
			/* if (!ft_strncmp(cmd->args[i], ">", 1))
				ft_output(cmd, i + 1);
			if (!ft_strncmp(cmd->args[i], "<", 1))
				ft_input(cmd, i + 1); */
			break ;
		}
		cmd->cmd[i] = ft_stephen_jokin(cmd, i);
	}
	cmd->cmd[i] = NULL;
	if (!cmd->flag)
		free(cmd->atrb);
	if (!ft_strncmp(*cmd->cmd, "|", 1) && ft_strlen(*cmd->cmd) == 1)
	{
		write(2, "bash: syntax error near unexpected token ", 42);
		write(2, *cmd->cmd, 1);
		write(2, "\n", 2);
		ft_doublefree(cmd->cmd);
		return ;
	}
	if (ft_builtings(cmd->cmd, cmd, env) == 1)
		exec_cmd(cmd->cmd, env->env);
	ft_doublefree(cmd->cmd);
}
