/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 08:07:56 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/25 11:34:25 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

char	*check_path(char **path, char *str)
{
	int		i;
	char	*aux;

	i = 0;
	aux = malloc(sizeof(char *));
	while (path[i] != NULL)
	{
		free (aux);
		aux = ft_strjoin(path[i], "/");
		if (access(str, X_OK) == 0)
		{
			free(aux);
			aux = ft_strdup(str);
			break ;
		}
		free (path[i]);
		path[i] = ft_strjoin(aux, str);
		free (aux);
		aux = ft_strdup(path[i++]);
		if (access(aux, X_OK) == 0)
			break ;
	}
	return (aux);
}

void	exec(char **cmd, t_env *env)
{
	char	**path;
	char	*aux;
	int		i;

	i = 0;
	aux = ft_path(env->env);
	if (!aux)
	{
		if (execve(*cmd, cmd, NULL) == -1)
			exit(error_code(*cmd, env));
		exit(error_code(*cmd, env));
	}
	path = ft_split(aux, ':');
	free (aux);
	aux = check_path(path, *cmd);
	if (aux && path[i] && !access(aux, X_OK))
		execve(aux, cmd, env->env);
	exit (error_code(*cmd, env));
}

int	exec_cmd(t_cmd	*cmd, t_env	*env)
{
	int		i;
	pid_t	pid;

	i = 0;
	signal(SIGINT, SIG_IGN);
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		signal(SIGINT, my_signal);
		open_fd(cmd);
		if (cmd->cmd && cmd->cmd[0] && ft_strlen(*cmd->cmd) > 0)
			exec(cmd->cmd, env);
		exit (0);
	}
	wait(&i);
	signal(SIGINT, my_signal);
	return (WEXITSTATUS(i));
}
