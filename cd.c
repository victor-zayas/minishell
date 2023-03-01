/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:31 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/01 15:35:23 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_oldpwd(t_env *env)
{
	int		i;
	char	*aux;

	i = -1;
	while (env->env[++i])
	{
		if (!env->env[i + 1])
		{
			aux = getcwd(NULL, 0);
			free(env->env[i]);
			env->env[i] = ft_strjoin("OLDPWD=", aux);
			free(aux);
			break ;
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
	free(env->pwd);
}

bool	ft_cd(t_cmd *args, t_env *env)
{
	char	*aux;

	if (!args->args[1])
	{
		aux = ft_find_home("HOME=", env);
		chdir(aux);
		free(aux);
		return (0);
	}
	get_oldpwd(env);
	args->flag = chdir(args->args[1]);
	if (args->flag == -1)
	{
		if (errno == EACCES)
			printf("bash: cd: %s: Permission denied\n", args->args[1]);
		else if (errno == ENOENT)
			printf("cd: %s: No such file or directory\n", args->args[1]);
		else
			printf("cd: %s: No such file or directory\n", args->args[1]);
		free(env->oldpwd);
		return (1);
	}
	ft_rewrite_pwd(env);
	return (0);
}
