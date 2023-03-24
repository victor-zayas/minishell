/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:36:07 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/24 11:55:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_name_end(char	*str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '"')
	{
		if (str[i] == '$')
		{
			i++;
			while (str[i] && ft_isalpha(str[i]))
				i++;
			break ;
		}
	}
	return (i);
}

int	get_name_start(char	*str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '"')
	{
		if (str[i] == '$')
			break ;
	}
	return (i);
}

int	get_name_len(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (i);
	}
	return (0);
}

char	*ft_find_home(char	*str, t_env	*env)
{
	char	*aux;
	int		start;

	start = -1;
	aux = NULL;
	while (env->env[++start])
	{
		if (!ft_strncmp(env->env[start], str, ft_strlen(str)))
		{
			aux = ft_substr(env->env[start], get_name_len(str) + 1,
					ft_strlen(env->env[start]) - get_name_len(str));
			return (aux);
		}
	}
	return (aux);
}

int	ft_env(t_cmd	*cmd, t_env *env, int open)
{
	int		i;
	pid_t	pid;

	i = -1;
	if (open)
	{
		pid = fork();
		if (pid == 0)
		{
			open_fd(cmd);
			ft_env(cmd, env, 0);
			exit (0);
		}
		waitpid(pid, NULL, 0);
		return (0);
	}
	while (env->env[++i])
		printf("%s\n", env->env[i]);
	return (0);
}
