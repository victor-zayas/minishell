/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:27:27 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/03/06 17:11:58 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int error_code(char *cmd, char	*path, int flag)
{
	if (flag == 3)
	{
		write(2, "bash: ", 7);
		write(2, cmd, ft_strlen(cmd));
		if (!ft_strncmp(cmd, "/", 1))
			write(2, ": Is a directory\n", 18);
		else
			write(2, ": command not found\n", 21);		
	}
	if (cmd == NULL || path == NULL) // comando no existente
		return (127);
	if (is_directory(cmd)) // permisos inadecuados
		return (126);
	return (0);
}

int is_directory(char *path)
{
	struct stat	statbuf;

	write(2, "bash: ", 7);
	write(2, path, ft_strlen(path));
	if (stat(path, &statbuf) != 0)
	{
		write(2, ": command not found\n", 21);
		return (0);
	}
	write(2, ": Is a directory\n", 18);
	printf("value of directory -> %d\n", S_ISDIR(statbuf.st_mode));
	return (S_ISDIR(statbuf.st_mode));
}
