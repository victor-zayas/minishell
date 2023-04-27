/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:36:07 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/04/27 12:20:00 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_name_end(char *str)
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

char	*ft_find_home(char *str, t_env *env)
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

int	ft_env(t_cmd *cmd, t_env *env, int open)
{
	int		i;
	int		flag;
	pid_t	pid;

	i = -1;
	if (open)
	{
		pid = fork();
		if (pid == 0)
		{
			if (open_fd(cmd))
				exit (1);
			exit (ft_env(cmd, env, 0));
		}
		waitpid(pid, &flag, 0);
		return (WEXITSTATUS(flag));
	}
	while (env->env[++i])
		printf("%s\n", env->env[i]);
	return (0);
}
