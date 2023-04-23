/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:44:17 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/23 16:45:10 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_get_heredoc(char	*arg)
{
	int		fd;
	char	*input;

	fd = open("heredoc_tmp", O_CREAT | O_RDWR | O_TRUNC, 0600);
	while (1)
	{
		input = readline("heredoc> ");
		if (ft_strlen(input) == ft_strlen(arg)
			&& !ft_strncmp(input, arg, ft_strlen(input)))
			break ;
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 2);
		free (input);
	}
	close(fd);
	free(input);
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

	pid = fork();
	if (pid == 0)
	{
		ft_get_heredoc(cmd->args[i]);
		exit (0);
	}
	waitpid(pid, NULL, 0);
	fd = open("heredoc_tmp", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	unlink("heredoc_tmp");
	return (EXIT_SUCCESS);
}
