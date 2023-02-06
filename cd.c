/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:31 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/06 11:45:53 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_oldpwd(t_env *env)
{
	char	**nw_env;
	int		u;
	int		i;

	u = 0;
	i = -1;
	nw_env = ft_bid_strdup(env->env);
	ft_bid_free(env->env);
	env->env = (char **)malloc(sizeof(char *) * (ft_bid_strlen(nw_env) + 2));
	while (nw_env[++i])
	{
		if (!ft_strncmp(nw_env[i], "PWD=", 4))
			env->env[u++] = ft_strjoin("OLDPWD=", env->oldpwd);
		env->env[u++] = ft_strdup(nw_env[i]);
	}
	env->env[u] = 0;
	ft_bid_free(nw_env);
}

static void	get_oldpwd(t_env *env)
{
	char	*var;
	int		i;
	
	i = -1;
	while (env->env[i])
	{
		if(!strncmp(env->env[i], "OLDPWD=", 7))
		{
			var = ft_strjoin("PWD=", env->pwd);
			if (strncmp(env->env[i + 1], var, ft_strlen(var)))
			{
				free(env->env[i]);
				env->env[i] = ft_strjoin("OLDPWD=", env->oldpwd);
			}
			free(var);
			return ;
		}
	}
	ft_oldpwd(env);
}

static void	ft_rewrite_pwd(t_env *env)
{
	int	i;

	i = -1;
	env->pwd = getcwd(NULL, 0);
	while (env->env[++i])
	{
		if (!ft_strncmp(env->env[i], "PWD=", 4))
		{
			free(env->env[i]);
			env->env[i] = ft_strjoin("PWD=", env->pwd);
		}
	}
}

//segfault L42
bool	ft_cd(t_cmd *args, t_env *env)
{
	get_oldpwd(env);
	if (chdir(args->args[1]) == -1)
	{
		printf("cd: %s: No such file or directory\n", args->args[1]);
		g_exit = 1;
		free(env->oldpwd);
		return (1);
	}
	ft_rewrite_pwd(env);
	return (0);
}
