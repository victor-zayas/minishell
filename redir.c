/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:56:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/08 10:54:50 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input(t_cmd	*cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
	while (cmd->args[i + 1] && !ft_strncmp(cmd->args[i + 1], "<", 1))
	{
		i++;
		if (cmd->args[i + 1])
			i++;
		else
		{
			write(2, "bash: syntax error near unexpected token `newline'\n", 52);
			return ;
		}
		fd = open(cmd->args[i], O_RDONLY);
		if (fd < 0)
			exit (EXIT_FAILURE);
	}
	dup2(fd, cmd->input);
	cmd->input = fd;
}

void	ft_output(t_cmd	*cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd < 0)
		exit (EXIT_FAILURE);
	while (cmd->args[i + 1] && !ft_strncmp(cmd->args[i + 1], ">", 1))
	{
		i++;
		if (cmd->args[i + 1])
			i++;
		else
		{
			write(2, "bash: syntax error near unexpected token `newline'\n", 52);
			return ;
		}
		fd = open(cmd->args[i], O_CREAT | O_RDWR | O_TRUNC, 0600);
		if (fd < 0)
			exit (EXIT_FAILURE);
	}
	dup2(fd, cmd->output);
	cmd->output = fd;
}
