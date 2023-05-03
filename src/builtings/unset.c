/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:45 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/24 16:11:42 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_msg(char *content, char *cmd)
{
	if (cmd != NULL)
	{
		write(2, "bash: ", 7);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": `", 4);
		write(2, content, ft_strlen(content));
		write(2, "': not a valid identifier\n", 27);
	}
	else
	{
		write(2, "bash: unset: ", 14);
		write(2, content, ft_strlen(content));
		write(2, " not a valid identifier ", 25);
		write(2, "\n", 2);
	}
}

int	content_check(t_env	*env, char	*content, char	*cmd)
{
	int	i;
	int	len;

	i = -1;
	len = -1;
	if (!content)
	{
		print_export(env->env);
		return (-1);
	}
	if (ft_isdigit(*content))
	{
		error_msg(content, cmd);
	}
	while (content[++len])
		if (content[len] == '=')
			break ;
	if (!content[len])
		return (-1);
	while (env->env[++i])
		if (!ft_strncmp(env->env[i], content, len))
			return (i);
	return (-2);
}

char	**ft_delete_val(t_env	*env, char	**aux, char	*content, int *pos)
{
	int	i;

	i = -1;
	while (env->env[++i])
	{
		if (ft_strchr(content, '='))
		{
			error_msg(content, NULL);
			free (aux);
			return (NULL);
		}
		if (!ft_strncmp(env->env[i], content, ft_strlen(content))
			&& get_name_len(env->env[i]) == (int)ft_strlen(content))
		{
			if (!env->env[i + 1])
				break ;
			free(env->env[i]);
			env->env[i] = ft_strdup(env->env[i + 1]);
		}
		aux[i] = ft_strdup(env->env[i]);
	}
	aux[i] = NULL;
	*pos = i;
	return (aux);
}

int	ft_unset(t_env *env, char *content)
{
	char	**aux;
	int		i;

	i = 0;
	if (!content)
		return (0);
	aux = malloc(sizeof(char *) * (ft_doublestrlen(env->env) + 1));
	if (!content)
		return (1);
	aux = ft_delete_val(env, aux, content, &i);
	if (!aux)
		return (0);
	ft_refill_env(env, aux, i);
	return (0);
}
