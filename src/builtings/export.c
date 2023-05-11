/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:29:52 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/11 06:49:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_export(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		printf("declare -x %s\n", env[i]);
}

char	**ft_alloc_env(t_env *env, char	*content, int flag, int *pos)
{
	int		i;
	char	**aux;

	i = -1;
	aux = NULL;
	if (flag == -2)
		aux = malloc(sizeof(char *) * (ft_doublestrlen(env->env) + 2));
	else
		aux = malloc(sizeof(char *) * (ft_doublestrlen(env->env) + 1));
	if (!aux)
		return (NULL);
	while (env->env[++i])
	{
		aux[i] = ft_strdup(env->env[i]);
		if (i == flag && flag >= 0
			&& !ft_strncmp(env->env[i], content, get_name_len(content)))
		{
			free(aux[i]);
			aux[i] = ft_strdup(content);
		}
	}
	*pos = i;
	return (aux);
}

void	ft_refill_env(t_env	*env, char	**aux, int i)
{
	ft_doublefree(env->env);
	env->env = malloc(sizeof(char *) * (ft_doublestrlen(aux) + 1));
	i = -1;
	while (aux[++i])
		env->env[i] = ft_strdup(aux[i]);
	env->env[i] = NULL;
	ft_doublefree(aux);
}

void	ft_new_content(t_env *env, char *content)
{
	char	**aux;
	int		i;

	i = -1;
	aux = ft_alloc_env(env, content, -2, &i);
	aux[i] = ft_strdup(content);
	aux[i + 1] = NULL;
	ft_refill_env(env, aux, i);
}

int	ft_export(t_env *env, char *content, char *cmd)
{
	int		i;
	int		flag;
	char	**aux;

	i = -1;
	aux = NULL;
	flag = content_check(env, content, cmd);
	if (flag == -1)
		return (1);
	if (flag == -2)
		ft_new_content(env, content);
	else
	{
		aux = ft_alloc_env(env, content, flag, &i);
		aux[i] = NULL;
		ft_refill_env(env, aux, i);
	}
	return (0);
}
