/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:32:03 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/16 15:53:20 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	exec(t_cmd	*token, char	**env)
{
	char	**args;
	char	*path;

	args  = NULL;
	if(ft_strchr(*token->args, '\'') != NULL)
		args = ft_split(*token->args, '\'');
	else if(ft_strchr(*token->args, '"') != NULL)
		args = ft_split(*token->args, '"');
	else
		args = ft_split(*token->args, ' ');
	path = get_cmd(*args, env);
	execve(path, args, env);
}

char	*ft_path(char	**enviroment_path)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (enviroment_path[i])
	{
		res = ft_strnstr(enviroment_path[i], "PATH=", 5);
		if (res)
		{
			res = ft_substr(enviroment_path[i], 5, ft_strlen(res));
			break ;
		}
		i++;
	}
	return (res);
}

char	*get_cmd(char	*arguments, char	**enviroment)
{
	char	**path;
	char	*env;
	char	*sup;
	char	*sup2;
	int		i;

	i = 0;
	env = ft_path(enviroment);
	path = ft_split(env, ':');
	free(env);
	while (path[i])
	{
		sup = ft_strjoin(path[i], "/");
		sup2 = ft_strjoin(sup, arguments);
		free(sup);
		if (access(sup2, 0) == 0)
			return (sup2);
		free (sup2);
		i++;
	}
	i = -1;
	while (path[++i])
		free (path[i]);
	free (path);
	return (0);
} */
