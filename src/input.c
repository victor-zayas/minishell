/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:44:17 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/17 17:28:25 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cat()
{
	char	**args;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		args = malloc(sizeof(char *) * 3);
		args[0] = "cat";
		args[1] = "heredoc_tmp";
		args[2] = NULL;
		execve("/bin/cat", args, NULL);
	}
	waitpid(pid, NULL, 0);
	return ;
}

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
	int		fd;
	char 	*str;

	pid = fork();
	if (pid == 0)
	{
		fd = open("heredoc_tmp", O_CREAT | O_RDWR | O_TRUNC, 0600);
		while (1)
		{
			str = readline("heredoc> ");
			if (ft_strlen(str) == ft_strlen(cmd->args[i])
				&& !ft_strncmp(str, cmd->args[i], ft_strlen(str)))
				break ;
			write(fd, str, ft_strlen(str));
			write(fd, "\n", 2);
			free (str);
		}
		close(fd);
		free(str);
		exit (0);
	}
	waitpid(pid, NULL, 0);
	fd = open("heredoc_tmp", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	unlink("heredoc_tmp");
	return (EXIT_SUCCESS);
}
