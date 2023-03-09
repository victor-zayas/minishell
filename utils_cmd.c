/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:27:27 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/03/09 16:28:22 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	error_code(char *cmd, t_env	*env)
{
	return (is_directory(cmd, env));
}

int	is_directory(char *path, t_env *env)
{
	struct stat	statbuf;

	write(2, "bash: ", 7);
	write(2, path, ft_strlen(path));
	if (stat(path, &statbuf) != 0)
	{
		write(2, ": command not found\n", 21);
		env->exit_value = 127;
		return (127);
	}
	write(2, ": Is a directory\n", 18);
	env->exit_value = 126;
	return (126);
}
