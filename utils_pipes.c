/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:14:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:29 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error(char	*error)
{
	size_t	len;

	len = ft_strlen(error);
	write(1, error, len);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	exec(char	**cmd, char	**enviroment)
{
	char	**path;
	char	*aux;
	int		i;

	i = 0;
	if (!cmd)
		return ;
	aux = ft_path(enviroment);
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
	for (int j = 0; cmd[j]; j++)
		printf("cmd[%d] -> [%s]", j, cmd[j]);
	if (aux)
		execve(aux, cmd, enviroment);
	exit (error_code(*cmd, path[i], 0));
}

void	ft_child(t_cmd	*cmd, t_env	*env, int	*fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (ft_builtings(cmd->cmd, cmd, env) == 1)
		exec(cmd->cmd, env->env);
	exit (1);
}

char	*ft_path(char	**enviroment_path)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (enviroment_path[i])
	{
		ret = ft_strnstr(enviroment_path[i], "PATH=", 5);
		if (ret)
		{
			ret = ft_substr(enviroment_path[i], 5, ft_strlen(ret));
			break ;
		}
		i++;
	}
	return (ret);
}

int	find_pipe(char	**args, int i)
{
	while (args[i])
	{
		if (ft_strchr(args[i], '|') || ft_strchr(args[i], '<')
			|| ft_strchr(args[i], '>'))
			break ;
		i++;
	}
	return (i);
}
