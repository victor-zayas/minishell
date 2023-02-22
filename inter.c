/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:55 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/22 23:21:19 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_name_len(char	*str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '=')
			return (i);
	}
	return (0);
}

void	find_env(char *str, int pos, t_env *env, t_cmd *cmd, int len)
{
	char	*aux;
	int		start;

	start = pos;
	if (str[pos + 1] && str[pos + 1] != ' ')
		pos++;
	while (str[pos] != '\'' && str[pos] != '"' && str[pos] != ' '
		&& str[pos] != '|' && str[pos] != '>' && str[pos] != '\t'
		&& str[pos] != '<' && str[pos] != '$' && str[pos] != '\0')
				pos++;
	aux = ft_substr(str, start + 1, pos);
	start = -1;
	while (env->env[++start])
	{
		if (!ft_strncmp(env->env[start], aux, get_name_len(env->env[start]))
			&& (int)ft_strlen(aux) == get_name_len(env->env[start]))
		{
			free(aux);
			free(cmd->args[len]);
			str = ft_substr(env->env[start], 0, ft_strlen(env->env[start]));
			aux = ft_substr(env->env[start], 0,
					get_name_len(env->env[start]) + 1);
			cmd->args[len] = ft_strtrim(str, aux);
			free (str);
			free (aux);
			return ;
		}
	}
	free(aux);
}

void	expand_dollars(char	*str, t_env *env, int pos, t_cmd	*cmd)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
		{
			find_env(str, i, env, cmd, pos);
			break ;
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
		if (ft_strchr(cmd->args[i], '\''))
		{
			aux = ft_strdup(cmd->args[i]);
			free(cmd->args[i]);
			cmd->args[i] = ft_strtrim(aux, "\'");
			free(aux);
		}
		else if (ft_strchr(cmd->args[i], '\"'))
		{
			aux = ft_strdup(cmd->args[i]);
			free(cmd->args[i]);
			cmd->args[i] = ft_strtrim(aux, "\"");
			free(aux);
			expand_dollars(cmd->args[i], env, i, cmd);
		}
		else
			expand_dollars(cmd->args[i], env, i, cmd);
	}
}
