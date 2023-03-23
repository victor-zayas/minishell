/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:43:41 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/23 17:59:03 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_output(t_cmd	*cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (cmd->args[i + 1] && !ft_strncmp(cmd->args[i + 1], ">", 1))
	{
		i++;
		if (cmd->args[i + 1])
			i++;
		else
		{
			write(2, "bash: syntax error near unexpected token `newline'\n", 52);
			return (0);
		}
		fd = open(cmd->args[i], O_CREAT | O_RDWR | O_TRUNC, 0600);
		if (fd < 0)
			return (EXIT_FAILURE);
	}
	dup2(fd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

int	ft_doutput(t_cmd	*cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_CREAT | O_RDWR | O_APPEND, 0644);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (cmd->args[i + 1] && !ft_strncmp(cmd->args[i + 1], ">>", 2))
	{
		i++;
		if (cmd->args[i + 1])
			i++;
		else
		{
			write(2, "bash: syntax error near unexpected token `newline'\n", 52);
			return (0);
		}
		fd = open(cmd->args[i], O_CREAT | O_RDWR | O_TRUNC, 0600);
		if (fd < 0)
			return (EXIT_FAILURE);
	}
	dup2(fd, 1);
	return (EXIT_SUCCESS);
}
