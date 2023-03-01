/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:55 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/01 15:52:32 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_env(int p_ar, int p_str, t_cmd	*cmd, t_env	*env)
{
	char	*aux;
	int		start;

	start = p_str;
	if (cmd->args[p_ar][p_str + 1] && cmd->args[p_ar][p_str + 1] != ' ')
		p_str++;
	p_str = i_cwords(cmd, cmd->args[p_ar], p_str);
	cmd->words--;
	if (cmd->args[p_ar][p_str])
		p_str--;
	aux = ft_substr(cmd->args[p_ar], start + 1, p_str);
	start = -1;
	while (env->env[++start])
	{
		if (!ft_strncmp(env->env[start], aux, get_name_len(env->env[start]))
			&& (int)ft_strlen(aux) == get_name_len(env->env[start]))
		{
			free(cmd->args[p_ar]);
			cmd->args[p_ar] = ft_substr(env->env[start],
				get_name_len(env->env[start]) + 1, ft_strlen(env->env[start]));
			break ;
		}
	}
	free(aux);
	return (p_str);
}

void	expand_dollars(int p_ar, t_cmd	*cmd, t_env	*env)
{
	int	i;

	i = -1;
	while (cmd->args[p_ar][++i] && cmd->args[p_ar])
	{
		if (cmd->args[p_ar][i] == '$' && cmd->args[p_ar])
		{
			i = find_env(p_ar, i, cmd, env);
			if (!cmd->args[p_ar][i])
				return ;
		}
	}
}

void	get_inter(t_cmd *cmd, t_env *env)
{
	int			i;
	char		*aux;

	i = -1;
	while (cmd->args[++i])
	{
		if (ft_strchr(cmd->args[i], '\'') || ft_strchr(cmd->args[i], '\"'))
		{
			if (ft_strchr(cmd->args[i], '\"'))
				cmd->flag = 1;
			else
				cmd->flag = 0;
			aux = ft_strdup(cmd->args[i]);
			free(cmd->args[i]);
			if (cmd->flag == 1)
				cmd->args[i] = ft_strtrim(aux, "\"");
			else
				cmd->args[i] = ft_strtrim(aux, "\'");
			free(aux);
			if (cmd->flag == 1)
				expand_dollars(i, cmd, env);
		}
		else if (!ft_strncmp(cmd->args[i], "$", 1)
			&& ft_strlen(cmd->args[i]) > 1)
			expand_dollars(i, cmd, env);
	}
}
