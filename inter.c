/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:55 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/14 18:53:11 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_inter(t_cmd *cmd, t_env *env)
{
	int			i;
	char	*aux;

	i = -1;
	while(cmd->args[++i])
	{
		aux = ft_strdup(cmd->args[i]);
		if (ft_strchr(cmd->args[i], '\''))
		{
			free(cmd->args[i]);
			cmd->args[i] = ft_strtrim(aux, "\'");
		}
		else if (ft_strchr(cmd->args[i], '\"'))
		{
			free(cmd->args[i]);
			cmd->args[i] = ft_strtrim(aux, "\"");
		}
		free (aux);
	}
	expand_dollars(cmd->args, env->env);
}

void	expand_dollars(t_cmd *cmd, t_env *env)
{
	int	i;
	int	j;	
	
	i = 0;
	j = 0;
	while (cmd->args[i] && env->env[j])
	{
		if (strchr(cmd->args[i], '$'))
					
	}
}