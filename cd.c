/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:20:31 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/07 18:43:12 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* void	get_oldpwd(t_env *env)
{
	char	*var;
	int		i;
	
	i = -1;
	while (env->env[++i])
	{
		if(env->env[i] && !ft_strncmp(env->env[i], "OLDPWD=", 7))
		{
			printf("entro");
			var = ft_strjoin("PWD=", env->pwd);
			if (ft_strncmp(env->env[i + 1], var, ft_strlen(var)))
			{
				free(env->env[i]);
				env->env[i] = ft_strjoin("OLDPWD=", env->oldpwd);
				printf("oldpwd:  %s\n", env->oldpwd);
			}
			free(var);
			return ;
		}
	}
} */

void    get_oldpwd(t_env *env)
{
    int        i;
    char    *aux;

    i = -1;
    while (env->env[++i])
    {
        if (!env->env[i + 1])
        {
            aux = getcwd(NULL, 0);
            env->env[i] = ft_strjoin("OLDPWD=", aux);
            free(aux);
            break ;
        }
    }
}

static void    ft_rewrite_pwd(t_env *env)
{
	int    i;

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
	get_oldpwd(env);
	printf("Cd arg: %s\n", args->args[1]);
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
