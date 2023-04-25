/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:38 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/04/25 16:49:34 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

int	ft_pipe_redir_output(char *str, int flag)
{
	int	fd;

	if (flag)
	{
		fd = open(str, O_CREAT | O_RDWR | O_APPEND, 0644);
		if (fd < 0)
			return (EXIT_FAILURE);
		dup2(fd, 1);
		return (EXIT_SUCCESS);
	}
	fd = open(str, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd < 0)
		return (EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_pipe_redir_input(char *str, int flag)
{
	int		fd;
	pid_t	pid;

	if (flag)
	{
		pid = fork();
		if (pid == 0)
		{
			ft_get_heredoc(str);
			exit (0);
		}
		waitpid(pid, NULL, 0);
		fd = open("heredoc_tmp", O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		unlink("heredoc_tmp");
		dup2(STDIN_FILENO, 0);
		return (EXIT_SUCCESS);
	}
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (EXIT_SUCCESS);
}

int	ft_pipe_redir_gen(char	**cmd, int cmd_start)
{
	int	flag;

	flag = 0;
	if (!ft_strncmp(cmd[cmd_start], ">", 1))
	{
		if (!ft_strncmp(cmd[cmd_start], ">>", 2))
			ft_pipe_redir_output(cmd[cmd_start + 1], 1);
		else
			ft_pipe_redir_output(cmd[cmd_start + 1], 0);
		flag = 1;
	}
	else if (!ft_strncmp(cmd[cmd_start], "<", 1))
	{
		if (!ft_strncmp(cmd[cmd_start], "<<", 2))
			ft_pipe_redir_input(cmd[cmd_start + 1], 1);
		else
			ft_pipe_redir_input(cmd[cmd_start + 1], 0);
	}
	return (flag);
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
			flag = ft_pipe_redir_gen(cmd, cmd_start);
		}
		cmd_start++;
	}
	return (flag);
}
