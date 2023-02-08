/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:18:02 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/08 12:35:15 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_cmd	*args, t_env	*env)
{
	int i;

	i = -1;
	if(args->args[1])
	{
		while(env->env[i + 1])
			i++;
		//env->env = malloc(sizeof(env->env) + 1);
		env->env[i + 1] = args->args[1];
		env->env[i + 2] = '\0';
	}
}

void	ft_unset(t_cmd	*args, t_env	*env)
{
	int i;

	i = -1;
	if(args->args[1])
	{
		while(env->env[i] && !ft_strncmp(env->env[i], args->args[1], ft_strlen(args->args[1])))
			i++;
		if (!env->env[i])
			return ;
		//env->env = malloc(sizeof(env->env) - 1);
		env->env[i] = "";
	}
}
