/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:18:02 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/09 19:34:13 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_arstr(char	**arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

void	print_export(char	**env)
{
	int	i;

	i = -1;
	while (env[++i])
		printf("declare -x %s\n", env[i]);
}

void	ft_export(t_env	*env, char *content)
{
	int		i;
	char	**aux;

	i = -1;
	if (!content)
	{
		print_export(env->env);
		return ;
	}
	aux = malloc(sizeof(char *) * (ft_bid_strlen(env->env) + 2));
	if (!aux)
		return ;
	while (env->env[++i])
		aux[i] = ft_strdup(env->env[i]);
	aux[i] = ft_strdup(content);
	aux[i + 1] = '\0';
	free_arstr(env->env);
	i = -1;
	while (aux[++i])
		env->env[i] = ft_strdup(aux[i]);
	env->env[i] = '\0';
	free_arstr(aux);
}

void	ft_unset(t_env	*env, char *content)
{
	int		i;
	char	*mem;
	char	**aux;

	if (!content)
		return ;
	aux = malloc(sizeof(char *) * (ft_bid_strlen(env->env) + 1) - 1);
	i = -1;
	mem = NULL;
	if (!content)
		return ;
	while (env->env[++i])
	{
		if (!strncmp(env->env[i], content, ft_strlen(content)) && env->env[i])
		{
			mem = env->env[i];
			if (!env->env[i + 1])
			{
				break ;
			}
			env->env[i] = ft_strdup(env->env[i + 1]);
			free(mem);
		}
		aux[i] = ft_strdup(env->env[i]);
	}
	aux[i] = '\0';
	free_arstr(env->env);
	i = -1;
	while (aux[++i])
		env->env[i] = ft_strdup(aux[i]);
	env->env[i] = '\0';
	free_arstr(aux);
}
