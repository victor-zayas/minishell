/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:14:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/15 17:45:05 by jaizpuru         ###   ########.fr       */
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

void	exec(t_cmd	*cmd, char	**enviroment, int	pos)
{
	char	**path;
	char	**arg_join;
	int		i;

	i = 0;
	path = ft_split(ft_path(enviroment), ':');
	arg_join = ft_split(cmd->args[pos], ' ');
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], *arg_join);
		execve(path[i], arg_join, enviroment);
		i++;
	}
	perror("zsh: command not found");
}

void	ft_child(t_cmd	*cmd, char	**enviroment1, int	*fds1, int	pos)
{
	if (cmd->n_cmd == 1)
		exec(cmd, enviroment1, pos - 1);
	//pwd |<-[1]fd[0]->| pwd |<-[1]fd[0]->| pwd
	close(fds1[FD_READ_END]);
	printf("		Child Command: %s\n", cmd->args[pos - 1]);
	dup2(fds1[FD_WRITE_END], STDOUT_FILENO);
	exec(cmd, enviroment1, pos - 1);
	close(fds1[FD_WRITE_END]);
}

void	ft_adult(t_cmd	*cmd, char	**enviroment2, int	*fds2, int	pos)
{
	close(fds2[FD_WRITE_END]);
	dup2(fds2[FD_READ_END], STDIN_FILENO);
	free(cmd->args[pos]);
	cmd->args[pos] = ft_strtrim(cmd->args[pos], "|");
	printf("		Adult Command: %s\n", cmd->args[pos]);
	exec(cmd, enviroment2, pos);
	close(fds2[FD_READ_END]);
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
