/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:27:27 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/03/08 17:19:02 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	error_code(char *cmd)
{
	return (is_directory(cmd));
}

int	is_directory(char *path)
{
	struct stat	statbuf;

	write(2, "bash: ", 7);
	write(2, path, ft_strlen(path));
	if (stat(path, &statbuf) != 0)
	{
		write(2, ": command not found\n", 21);
		return (126);
	}
	write(2, ": Is a directory\n", 18);
	return (127);
}
