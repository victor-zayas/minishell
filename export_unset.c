/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:18:02 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/09 16:14:59 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_env	*env, char *content)
{
	int 	i;
	char	**aux;

	i = -1;
	if (!content)
		return ;
	aux = malloc(sizeof(char * ) * (ft_bid_strlen(env->env) + 2));
	if (!aux)
		return ;
	while (env->env[++i])
		aux[i] = ft_strdup(env->env[i]);
	aux[i] = ft_strdup(content);
	//printf("EXPORT::::  %s\n", aux[i]);
	aux[i + 1] = '\0';
	free(env->env);
	env->env = aux;
}

void    ft_unset(t_env    *env, char *content)
{
    int     i;

    i = -1;
    if (!content)
        return ;
    while (env->env[++i])
    {
        if(!strncmp(env->env[i], content, ft_strlen(content)))
            break ;
    }
    if (!env->env[i])
        return ;
    env->env[i] = NULL;
}
