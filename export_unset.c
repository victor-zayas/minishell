/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 16:22:45 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/08 12:37:59 by vzayas-s         ###   ########.fr       */
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
		return (-1); // return value for exiting
	}
	if (ft_isdigit(*content))
	{
		write(2, "bash: ", 7);
		write(2, cmd, ft_strlen(cmd));
		write(2, ": `", 4);
		write(2, content, ft_strlen(content));
		write(2, "': not a valid identifier\n", 27);
	}
	while (content[++len]) // get length of content until '='
		if (content[len] == '=')
			break ;
	if (!content[len])
		return (-1); // return value for exiting
	while (env->env[++i])
		if (!ft_strncmp(env->env[i], content, len)) // if it is found any variable with the same name and length of content
			return (i); // return the position of the string in the enviroment
	return (-2); // if not found, return value for creating a new variable
}

void	print_export(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		printf("declare -x %s\n", env[i]);
}

void	ft_export(t_env *env, char *content, char *cmd)
{
	int		i;
	int		flag;
	char	**aux;

	i = -1;
	flag = content_check(env, content, cmd); // function that clasifies content in three values
	// -1 : Content is invalid, no '=' or not existant
	// -2 : Content is valid, but does not exist inside enviroment
	// (i) : Content is found inside the enviroment
	if (flag == -1)
		return ;
	if (flag == -2)
		aux = malloc(sizeof(char *) * (ft_doublestrlen(env->env) + 2));
	else
		aux = malloc(sizeof(char *) * (ft_doublestrlen(env->env) + 1));
	if (!aux)
		return ;
	while (env->env[++i])
	{
		aux[i] = ft_strdup(env->env[i]); // aux is gonna copy every line of enviroment
		if (i == flag && flag >= 0
			&& !ft_strncmp(env->env[i], content, get_name_len(content))) // if content is found inside enviroment (i)
		{
			free(aux[i]); // free the line that was copied above in this iteration
			aux[i] = ft_strdup(content); // copy actually the content (input) that the user wants it to be
		}
	}
	// in this point enviroment is in the top bottom.
	if (flag == -2) // in case it does not already exist in enviroment (-2)
	{
		aux[i] = ft_strdup(content); // copy the content in the last slot
		aux[i + 1] = NULL; // close the array of strings
	}
	else // in case we modified the value (i)
		aux[i] = NULL; // close the array of strings
	ft_doublefree(env->env); // we free the enviroment for a new copy of it
	env->env = malloc(sizeof(char *) * (ft_doublestrlen(aux) + 1)); // we allocate memory for enviroment
	i = -1; // we need a loop to copy all the strings into enviroment
	while (aux[++i])
		env->env[i] = ft_strdup(aux[i]);
	env->env[i] = NULL;
	ft_doublefree(aux); // free the auxiliar array of strings to avoid leaks
}

void	ft_unset(t_env *env, char *content)
{
	int		i;
	char	*mem;
	char	**aux;

	if (!content)
		return ;
	aux = malloc(sizeof(char *) * (ft_doublestrlen(env->env) + 1));
	mem = NULL;
	if (!content)
		return ;
	i = -1;
	while (env->env[++i])
	{
		if (!strncmp(env->env[i], content, ft_strlen(content)) && env->env[i])
		{
			mem = ft_strdup(env->env[i]);
			if (!env->env[i + 1])
				break ;
			free(env->env[i]);
			env->env[i] = ft_strdup(env->env[i + 1]);
			free(mem);
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
}
