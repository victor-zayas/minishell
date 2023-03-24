/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:31 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/24 14:30:07 by jaizpuru         ###   ########.fr       */
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

int	cd_error_flag(t_env	*env, char	*str, int flag)
{
	if (flag == -1)
	{
		if (errno == EACCES)
			printf("bash: cd: %s: Permission denied\n", str);
		else if (errno == ENOENT)
			printf("cd: %s: No such file or directory\n", str);
		else if (errno == ENOTDIR)
			printf("cd: %s: Not a directory\n", str);
		else
			printf("cd: %s: No such file or directory\n", str);
		free(env->oldpwd);
		env->exit_value = 1;
		return (1);
	}
	return (0);
}

int	ft_cd(char	**cmd, t_cmd	*args, t_env *env)
{
	char	*aux;
	int		flag;
	int		i;

	i = 1;
	if (!cmd[i])
	{
		aux = ft_find_home("HOME=", env);
		if (aux == NULL)
			return (1);
		chdir(aux);
		return (free(aux), 0);
	}
	get_oldpwd(env);
	args->flag = chdir(cmd[i]);
	flag = cd_error_flag(env, cmd[i], args->flag);
	return (ft_rewrite_pwd(env), flag);
}
