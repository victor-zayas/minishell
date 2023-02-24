/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:56:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/24 01:10:15 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_input(t_cmd	*cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
}

void	ft_output(t_cmd	*cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (fd < 0)
		exit (EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
}
