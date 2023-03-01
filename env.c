/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:36:07 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/01 15:35:45 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			aux = ft_substr(env->env[start], get_name_len(str) + 1, ft_strlen(env->env[start]) - get_name_len(str));
			return (aux);
		}
	}
	return (aux);
}

void	ft_env(t_env *env)
{
	int	i;

	i = -1;
	while (env->env[++i])
		printf("%s\n", env->env[i]);
}
