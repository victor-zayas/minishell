/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:31 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/05 11:28:06 by jaizpuru         ###   ########.fr       */
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

bool	ft_cd(char	**cmd, t_cmd	*args, t_env *env)
{
	char	*aux;
	int		i;

	i = 1;
	if (!cmd[i])
	{
		aux = ft_find_home("HOME=", env);
		chdir(aux);
		free(aux);
		return (0);
	}
	get_oldpwd(env);
	args->flag = chdir(cmd[i]);
	if (args->flag == -1)
	{
		if (errno == EACCES)
			printf("bash: cd: %s: Permission denied\n", cmd[i]);
		else if (errno == ENOENT)
			printf("cd: %s: No such file or directory\n", cmd[i]);
		else if (errno == ENOTDIR)
			printf("cd: %s: Not a directory\n", cmd[i]);
		else
			printf("cd: %s: No such file or directory\n", cmd[i]);
		free(env->oldpwd);
		return (1);
	}
	ft_rewrite_pwd(env);
	return (0);
}
