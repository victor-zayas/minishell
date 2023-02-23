/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:30:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/23 16:32:37 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		aux = ft_path(enviroment);
		path = ft_split(aux, ':');
		free (aux);
		while (path[i] != NULL)
		{
			aux = ft_strjoin(path[i], "/");
			free (path[i]);
			path[i] = ft_strjoin(aux, *cmd);
			free (aux);
			aux = ft_strdup(path[i++]);
			if (access(aux, X_OK) == 0)
				break ;
			free (aux);
		}
		if (aux)
			execve(aux, cmd, enviroment);
		write(2, "bash:", 6);
		write(2, ": command not found\n", 21);
	}
	waitpid(pid, NULL, 0);
	ft_doublefree(cmd);
	return ;
}

char	*ft_stephen_jokin(t_cmd *cmd, int i)
{
	char	*aux;

	if (ft_strchr(cmd->args[i], '|') || ft_strchr(cmd->args[i], '<')
		|| ft_strchr(cmd->args[i], '>'))
		return (NULL);
	aux = ft_strdup(cmd->args[i]);
	return (aux);
}

void	ft_selector(t_cmd *cmd, t_env *env)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	cmd->cmd = (char **)malloc(sizeof(char *) * (find_pipe(cmd->args, 0) + 1));
	if (!cmd->cmd)
		return ;
	cmd->atrb = (char **)malloc(sizeof(char *)
			* (find_pipe(cmd->args, find_pipe(cmd->args, 0)) + 1));
	if (!cmd->atrb)
		return ;
	while (cmd->args[++i])
	{
		if (!ft_strncmp(cmd->args[i], "|", 1))
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
		cmd->cmd[i] = ft_stephen_jokin(cmd, i);
	}
	cmd->cmd[i] = NULL;
	free(cmd->atrb);
	exec_cmd(cmd->cmd, env->env);
}
