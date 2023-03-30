/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:27:27 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/03/30 11:41:07 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	close_str(char	**ar, int end, int sp)
{
	if (sp)
		ar[sp] = NULL;
	else
		ar[end] = NULL;
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
