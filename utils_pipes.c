/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:14:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/16 20:34:51 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
# define FD_READ_END	0
# define FD_WRITE_END	1

void	error(char	*error)
{
	size_t	len;

	len = ft_strlen(error);
	write(1, error, len);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	exec(char	**cmd, char	**enviroment)
{
	char	**path;
	int		i;

	i = 0;
	if (!cmd)
		return ;
	path = ft_split(ft_path(enviroment), ':');
	/*for (int i = 0; cmd[i]; i++)
	{
		write(2, cmd[i], ft_strlen(cmd[i]));
		write(2, "\n", 1);
	}*/
	path[i] = ft_strjoin(path[i], "/");
	path[i] = ft_strjoin(path[i], *cmd);
	while (path[i])
	{
		//coger aqui el path;
		i++;
	}
	execve(path[i], cmd, enviroment);
	perror("zsh: command not found");
	exit(1);
}

void	ft_child(char	**cmd, char	**enviroment1, int	*fds1)
{
	dup2(fds1[FD_WRITE_END], STDOUT_FILENO);
	close(fds1[FD_READ_END]);
	close(fds1[FD_WRITE_END]);
	exec(cmd, enviroment1);
}

//HIJO
//pipe(fd)
//dup2(fds[WRITE_END], 1)
//close(fd[WRITE_END])
//close(fd[READ_END])

//PADRE
//DUP2(fds[READ_END], 0)
//close(fd[WRITE_END])
//close(fd[READ_END])

void	ft_adult(char	**cmd, char	**enviroment2, __unused int	*fds2)
{
	dup2(1, fds2[FD_WRITE_END]);
	//close(fds2[FD_WRITE_END]);
	//close(fds2[FD_READ_END]);
	exec(cmd, enviroment2);
}

char	*ft_path(char	**enviroment_path)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (enviroment_path[i])
	{
		ret = ft_strnstr(enviroment_path[i], "PATH=", 5);
		if (ret)
		{
			ret = ft_substr(enviroment_path[i], 5, ft_strlen(ret));
			break ;
		}
		i++;
	}
	return (ret);
}
