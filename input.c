/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:44:17 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/13 17:28:19 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_input(t_cmd *cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (cmd->args[i + 1] && !ft_strncmp(cmd->args[i + 1], "<", 1))
	{
		i++;
		if (cmd->args[i + 1])
			i++;
		else
		{
			write(2, "bash: syntax error near unexpected token `newline'\n", 52);
			return (0);
		}
		fd = open(cmd->args[i], O_RDONLY);
		if (fd < 0)
			return (EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	return (EXIT_SUCCESS);
}

int	ft_dinput(t_cmd	*cmd, int i)
{
	pid_t	pid;
	int		fd[2];
	char 	*str;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[1]);
		dup2(fd[0], STDOUT_FILENO);
		close(fd[0]);
		while (1)
		{
			str = readline("heredoc> ");
			if (ft_strlen(str) == ft_strlen(cmd->args[i])
				&& !ft_strncmp(str, cmd->args[i], ft_strlen(str)))
				break ;
			write(fd[0], str, ft_strlen(str));
			write(fd[0], "\n", 2);
			free (str);
		}
		free(str);
		exit (0);
	}
	waitpid(pid, NULL, 0);
	close(fd[0]);
	dup2(fd[1], STDIN_FILENO);
/* 	char	*args[] = { "bin/cat", NULL };
	exec(args, NULL); */
	return (EXIT_SUCCESS);
}
