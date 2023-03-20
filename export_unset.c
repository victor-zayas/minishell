/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:45 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/20 17:58:11 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		write(2, "bash: ", 7);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": `", 4);
		write(2, content, ft_strlen(content));
		write(2, "': not a valid identifier\n", 27);
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

void	print_export(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		printf("declare -x %s\n", env[i]);
}

int	ft_export(t_env *env, char *content, char *cmd)
{
	int		i;
	int		flag;
	char	**aux;

	i = -1;
	flag = content_check(env, content, cmd);
	if (flag == -1)
		return (0);
	if (flag == -2)
		aux = malloc(sizeof(char *) * (ft_doublestrlen(env->env) + 2));
	else
		aux = malloc(sizeof(char *) * (ft_doublestrlen(env->env) + 1));
	if (!aux)
		return (1);
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
	if (flag == -2)
	{
		aux[i] = ft_strdup(content);
		aux[i + 1] = NULL;
	}
	else
		aux[i] = NULL;
	ft_doublefree(env->env);
	env->env = malloc(sizeof(char *) * (ft_doublestrlen(aux) + 1));
	i = -1;
	while (aux[++i])
		env->env[i] = ft_strdup(aux[i]);
	env->env[i] = NULL;
	ft_doublefree(aux);
	return (0);
}

int	ft_unset(t_env *env, char *content)
{
	int		i;
	char	**aux;

	if (!content)
	{
		write(2, "unset: not enough arguments\n", 29);
		return (0);
	}
	aux = malloc(sizeof(char *) * (ft_doublestrlen(env->env) + 1));
	if (!content)
		return (1);
	i = -1;
	while (env->env[++i])
	{
		if (ft_strchr(content, '='))
		{
			write(2, "bash: unset: ", 14);
			write(2, content, ft_strlen(content));
			write(2, "not a valid identifier ", 24);
			write(2, "\n", 2);
			free (aux);
			return (0);
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
	ft_doublefree(env->env);
	env->env = malloc(sizeof(char *) * (ft_doublestrlen(aux) + 1));
	i = -1;
	while (aux[++i])
		env->env[i] = ft_strdup(aux[i]);
	env->env[i] = NULL;
	ft_doublefree(aux);
	return (0);
}
