/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:14:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/10/25 17:00:36 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char	**f_arguments, char	*f_cmd)
{
	int	i;

	i = -1;
	while (f_arguments[++i])
		free(f_arguments[i]);
	write(2, "command has not been found!", 28);
	write(2, "\n", 2);
	free(f_cmd);
}

char	*ft_path(char	**enviroment_path)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (enviroment_path[i])
	{
		res = ft_strnstr(enviroment_path[i], "PATH=", 5);
		if (res)
		{
			res = ft_substr(enviroment_path[i], 5, ft_strlen(res));
			break ;
		}
		i++;
	}
	return (res);
}

char	*get_cmd(char	*arguments, char	**enviroment)
{
	char	**path;
	char	*env;
	char	*sup;
	char	*sup2;
	int		i;

	i = 0;
	env = ft_path(enviroment);
	path = ft_split(env, ':');
	free(env);
	while (path[i])
	{
		sup = ft_strjoin(path[i], "/");
		sup2 = ft_strjoin(sup, arguments);
		free(sup);
		if (access(sup2, 0) == 0)
			return (sup2);
		free (sup2);
		i++;
	}
	i = -1;
	while (path[++i])
		free (path[i]);
	free (path);
	return (0);
}

void	ft_child(int fd1, char	*arguments1, char	**enviroment1, int	*fds1)
{
	char	*cmd1;
	char	**args1;

	close(fds1[FD_READ_END]);
	dup2(fd1, STDIN_FILENO);
	dup2(fds1[FD_WRITE_END], STDOUT_FILENO);
	args1 = ft_split(arguments1, ' ');
	cmd1 = get_cmd(*args1, enviroment1);
	if (!cmd1)
	{
		close(fd1);
		close(fds1[FD_WRITE_END]);
		ft_free(args1, cmd1);
		exit(EXIT_FAILURE);
	}
	if (execve(cmd1, args1, enviroment1) == -1)
		error("execution failed!");
	close(fd1);
	close(fds1[FD_WRITE_END]);
	exit(EXIT_SUCCESS);
}

void	ft_adult(int fd2, char	*arguments2, char	**enviroment2, int	*fds2)
{
	char	*cmd2;
	char	**args2;

	close(fds2[FD_WRITE_END]);
	dup2(fd2, STDOUT_FILENO);
	dup2(fds2[FD_READ_END], STDIN_FILENO);
	args2 = ft_split(arguments2, ' ');
	cmd2 = get_cmd(*args2, enviroment2);
	if (!cmd2)
	{
		close(fd2);
		close(fds2[FD_READ_END]);
		ft_free(args2, cmd2);
		exit(EXIT_FAILURE);
	}
	if (execve(cmd2, args2, enviroment2) == -1)
		error("execution failed!");
	close(fd2);
	close(fds2[FD_READ_END]);
}
