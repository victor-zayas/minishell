/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_expand.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:15:55 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 12:30:34 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"


/**
 * @brief In this function the string of the dollar token is
 * 			checked in the Enviroment.
 * 
 * 			In case it is found, the content of the token changes
 * 			to its expanded value.
 * 
 * @param cmd Structure that holds tokens, cmd, fds...
 * @param env Structure holding enviroment, tokens, ...
 * @param aux Dollar token to be expanded.
 * @param p_ar Position[array] of the dollar token inside the array of string.
 */
void	ft_findtokenval(t_cmd *cmd, t_env *env, char *aux, int p_ar)
{
	int	start;

	start = cmd->i.i3;
	while (env->env[++start])
	{
		if (!ft_strncmp(env->env[start], aux, get_name_len(env->env[start]))
			&& (get_name_end(cmd->args[p_ar]) - get_name_start(cmd->args[p_ar])
				- 1 == get_name_len(env->env[start])))
		{
			free(cmd->args[p_ar]);
			cmd->args[p_ar] = ft_substr(env->env[start],
					get_name_len(env->env[start]) + 1,
					ft_strlen(env->env[start]));
			break ;
		}
	}
}

/**
 * @brief 
 * 
 * @param p_ar Array[array][s] position of the token variable [cmd->args].
 * @param p_str String[a][string] position of the token variable [cmd->args].
 * @param cmd Structure that holds tokens, cmd, fds...
 * @param env Structure holding enviroment, tokens, ...
 * @return int Position of the string after the dollar token.
 */
int	ft_gettokenval(int p_ar, int p_str, t_cmd	*cmd, t_env	*env)
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
	cmd->i.i3 = start;
	ft_findtokenval(cmd, env, aux, p_ar);
	return (free(aux), p_str);
}

/**
 * @brief In this function dollar tokens are expanded using
 * 			different sources, as [env] or [exit_val].
 * 
 * @param p_ar Position of the token inside double-str of cmd->args.
 * @param cmd Structure that holds tokens, cmd, fds...
 * @param env Structure holding enviroment, tokens, ...
 */
void	ft_expand_dollars(int p_ar, t_cmd	*cmd, t_env	*env)
{
	int	i;

	i = -1;
	while (cmd->args[p_ar][++i] && cmd->args[p_ar])
	{
		if (!ft_strncmp(cmd->args[p_ar], "$?", 2)
			&& ft_strlen(cmd->args[p_ar]) == 2)
		{
			free(cmd->args[p_ar]);
			cmd->args[p_ar] = ft_itoa(env->exit_value);
			return ;
		}
		if (cmd->args[p_ar][i] == '$' && cmd->args[p_ar]
			&& ft_isalpha(cmd->args[p_ar][i + 1]))
		{
			i = ft_gettokenval(p_ar, i, cmd, env);
			return ;
		}
	}
}

/**
 * @brief This function is primarily designed for trimming quotes,
 * 			and if any dollar token is found inside a double quote
 * 			it is also expanded as the other ones.
 * 
 * @param cmd Structure that holds tokens, cmd, fds...
 * @param env Structure holding enviroment, tokens, ...
 * @param i The position inside args that holds the string to be modified.
 */
void	ft_quote_trim(t_cmd	*cmd, t_env	*env, int i)
{
	char	*aux;

	if (ft_strchr(cmd->args[i], '\"'))
		cmd->flag = 1;
	else
		cmd->flag = 0;
	aux = ft_strdup(cmd->args[i]);
	if (ft_strchr(cmd->args[i], '>') || ft_strchr(cmd->args[i], '<')
		|| ft_strchr(cmd->args[i], '|'))
		return (free (aux));
	free(cmd->args[i]);
	if (cmd->flag == 1)
		cmd->args[i] = ft_strtrim(aux, "\"");
	else
		cmd->args[i] = ft_strtrim(aux, "\'");
	free(aux);
	if (cmd->flag == 1)
		ft_expand_dollars(i, cmd, env);
}

/**
 * @brief This functions cuts and expands different tokens:
 * 			Any closed simple & double quote is trimmed and resized
 * 			in the cmd structure.
 * 			Any acceptable dollar token is expanded to its value, if it
 * 			is found.
 * 
 * @param cmd Structure that holds tokens, cmd, fds...
 * @param env Structure holding enviroment, tokens, ...
 */
void	ft_trimexpand(t_cmd *cmd, t_env *env)
{
	int			i;

	i = -1;
	while (cmd->args[++i])
	{
		if (ft_strchr(cmd->args[i], '\'') || ft_strchr(cmd->args[i], '\"'))
			ft_quote_trim(cmd, env, i);
		else if (!ft_strncmp(cmd->args[i], "$", 1)
			&& ft_strlen(cmd->args[i]) > 1)
			ft_expand_dollars(i, cmd, env);
	}
}
