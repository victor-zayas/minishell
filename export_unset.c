/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/02/13 19:50:42 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

int	content_check(t_env	*env, char	*content)
{
	int	i;
	int	len;

	i = -1;
	len = -1;
	if (!content)
	{
		print_export(env->env);
		return (1);
	}
	while (content[++len])
	{
		if (content[len] == '=')
			break ;
	}
	if (!content[len])
		return (1);
	while(env->env[++i])
	{
		if (!ft_strncmp(env->env[i], content, len))
			return (i);
	}
	return (0);
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
	int		flag;
	char	**aux;

	i = -1;
	flag = content_check(env, content);
	printf("				FLAG -> %d\n", flag);
	if (flag == 1)
		return ;
	if (flag == 0)
		aux = malloc(sizeof(char *) * (ft_bid_strlen(env->env) + 2));
	else
		aux = malloc(sizeof(char *) * (ft_bid_strlen(env->env) + 1));
	if (!aux)
		return ;
	while (env->env[++i])
	{
		if(i == flag && i > 1)
		{
			aux[i] = ft_strdup(content);
			printf("				AUX[I] -> %s\n", aux[i]);
			if (env->env[i + 1])
				i++;
			else
				break ;
		}
		aux[i] = ft_strdup(env->env[i]);
	}
	if (flag == 0)
	{
		aux[i] = ft_strdup(content);
		aux[i + 1] = NULL;
	}
	else
		aux[i + 1] = NULL;
	//ft_bid_free(env->env);
	i = -1;
	while (aux[++i])
		env->env[i] = ft_strdup(aux[i]);
	env->env[i] = NULL;
	ft_bid_free(aux);
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
	aux[i] = NULL;
	ft_bid_free(env->env);
	i = -1;
	while (aux[++i])
		env->env[i] = ft_strdup(aux[i]);
	env->env[i] = NULL;
	ft_bid_free(aux);
}
