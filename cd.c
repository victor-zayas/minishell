/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:25:10 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/01/26 17:57:59 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

static void	ft_get_oldpwd(t_env *env, char *pwd)
{
	char	*aux;
	int		i;

	i = -1;
	env->oldpwd = getcwd(NULL, 0);
	while (env->env[i++])
	{
		if (!ft_strncmp(env->env[i], "OLDPWD=", 7))
		{
			aux = ft_strjoin("PWD=", pwd);
			if (ft_strncmp(env->env[i + 1], aux, ft_strlen(aux)))
			{
				free(env->env[i]);
				env->env[i] = ft_strjoin("OLDPWD=", env->oldpwd);
			}
			free(aux);
			return ;
		}
	}
	ft_oldpwd(env);
}

void	ft_oldpwd(t_env *env)
{
	char	new_env;
	int		i;
	int		j;
	
	i = -1;
	j = 0;
	new_env = ft_bid_strdup(env->env);
	ft_bid_strlen(env->env);
	env->env = (char**)malloc(sizeof(char *) * (ft_bid_strlen(new_env) + 2));
	while (new_env[++i])
	{
		if (!ft_strncmp(new_env[i], "PWD=", 4))
			env->env[j++] = ft_strjoin("OLDPWD=", env->oldpwd);
		env->env[j++] = ft_strdup(new_env[i]);
	}
	env->env[j] = '\0';
	ft_bid_free(new_env);
}

