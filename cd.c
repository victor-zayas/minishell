/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:31 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/06 18:20:52 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	get_oldpwd(t_env *env)
{
	char	*var;
	int		i;
	
	i = -1;
	while (env->env[++i])
	{
		if(env->env[i] && !ft_strncmp(env->env[i], "OLDPWD=", 7))
		{
			var = ft_strjoin("PWD=", env->pwd);
			if (ft_strncmp(env->env[i + 1], var, ft_strlen(var)))
			{
				free(env->env[i]);
				env->env[i] = ft_strjoin("OLDPWD=", env->oldpwd);
			}
			free(var);
			return ;
		}
	}
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

bool	ft_cd(t_cmd *args, t_env *env)
{
	get_oldpwd(env);
	if (chdir(args->args[1]) == -1)
	{
		printf("cd: %s: No such file or directory\n", args->args[1]);
		free(env->oldpwd);
		g_exit = 1;
		return (1);
	}
	ft_rewrite_pwd(env);
	return (0);
}

