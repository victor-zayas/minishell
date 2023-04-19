/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:38 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/03/31 11:46:01 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	getstdio(int *stdio)
{
	stdio[0] = dup(STDIN_FILENO);
	stdio[1] = dup(STDOUT_FILENO);
}

void	resetstdio(int *stdio)
{
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
}

int	ft_pipe_redir_output(char *str)
{
	int	fd;

	fd = open(str, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd < 0)
		return (EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_pipe_redir_input(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_check_redir(char **cmd, int cmd_start)
{
	int		flag;

	flag = 0;
	while (cmd[cmd_start] && ft_strncmp(cmd[cmd_start], "|", 1))
	{
		if (!ft_strncmp(cmd[cmd_start], ">", 1)
			|| !ft_strncmp(cmd[cmd_start], "<", 1))
		{
			if (!ft_strncmp(cmd[cmd_start], ">", 1))
			{
				ft_pipe_redir_output(cmd[cmd_start + 1]);
				flag = 1;
			}
			else if (!ft_strncmp(cmd[cmd_start], "<", 1))
				ft_pipe_redir_input(cmd[cmd_start + 1]);
		}
		cmd_start++;
	}
	return (flag);
}
