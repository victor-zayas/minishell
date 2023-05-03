/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:31 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/05/02 01:40:47 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Get the oldpwd PATH
 * 
 * @param env Copied enviroment.
 */
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

/**
 * @brief This function rewrite PWD in case it change.
 * 
 * @param env Copied enviroment to modified.
 */
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

/**
 * @brief This function check if command flag and send an error message
 * 		  if it's an error.
 * 
 * @param env Copied enviroment.
 * @param str Command received.
 * @param flag Int of flag command.
 * @return int 
 */
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

/**
 * @brief This funciton checks the "-" flag of cd builting.
 * 
 * @param env Copied enviroment.
 * @param cmd Command "cd" with option.
 * @return int 
 */
int	check_option(t_env	*env, char	**cmd)
{
	int		flag;
	int		i;
	char	*str;

	i = 1;
	if (!ft_strncmp(cmd[i], "-", 1) && ft_strlen(cmd[i]) == 1)
	{
		flag = content_check(env, "OLDPWD=", "export");
		if (flag < 0 || !env->env[flag])
			return (ft_putstr_fd("bash: cd: OLDPWD not set\n", 2), 2);
		str = ft_substr(env->env[flag],
				get_name_len(env->env[flag]) + 1, ft_strlen(env->env[flag]));
		get_oldpwd(env);
		if (!chdir(str))
			free(str);
		return (ft_rewrite_pwd(env), 1);
	}
	return (0);
}

/**
 * @brief This function, replicate the "CD" builting wich move you
 * between directories, (Change Directory).
 * 
 * @param cmd Commands from prompt.
 * @param args Option command.
 * @param env Copied enviroment to change the $PWD value.
 * @return int 
 */
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
	flag = check_option(env, cmd);
	if (flag == 1)
		return (0);
	if (flag == 2)
		return (1);
	get_oldpwd(env);
	args->flag = chdir(cmd[i]);
	flag = cd_error_flag(env, cmd[i], args->flag);
	return (ft_rewrite_pwd(env), flag);
}
