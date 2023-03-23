/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:14:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/23 15:57:31 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_string_trader(t_cmd *cmd, int start)
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
}

void	error(char	*error)
{
	size_t	len;

	len = ft_strlen(error);
	write(1, error, len);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	exec(char **cmd, t_env *env)
{
	char	**path;
	char	*aux;
	int		i;

	i = 0;
	if (!cmd)
		return ;
	aux = ft_path(env->env);
	if (!aux)
	{
		if (execve(*cmd, cmd, NULL) == -1)
			exit(error_code(*cmd, env));
		exit(error_code(*cmd, env));
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
		execve(aux, cmd, env->env);
	exit (error_code(*cmd, env));
}

void	ft_child(t_cmd	*cmd, t_env	*env, int	*fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (ft_builtings(cmd->cmd, cmd, env, 0) == 1)
		exec(cmd->cmd, env);
	exit (1);
}

char	*ft_path(char **enviroment_path)
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
		if (ft_strchr(args[i], '|') || ft_strchr(args[i], '>')
			|| ft_strchr(args[i], '<'))
			break ;
		i++;
	}
	return (i);
}
