/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:56:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/20 16:20:03 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_dinput(t_cmd	*cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_RDONLY);
	if (fd < 0)
		exit (EXIT_FAILURE);
	while (cmd->args[i + 1] && !ft_strncmp(cmd->args[i + 1], "<<", 2))
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
	dup2(fd, 0);
}

void	ft_doutput(t_cmd	*cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_CREAT | O_RDWR | O_TRUNC | O_APPEND, 0600);
	if (fd < 0)
		exit (EXIT_FAILURE);
	while (cmd->args[i + 1] && !ft_strncmp(cmd->args[i + 1], ">>", 2))
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
	dup2(fd, 1);
}

void	open_fd(t_cmd	*cmd)
{
	int	i;

	cmd->in_it = 0;
	cmd->out_it = 0;
	i = 0;
	while (cmd->args[++i] && (cmd->greater >= 1 || cmd->lesser >= 1
			|| cmd->double_in >= 1 || cmd->double_out >= 1))
	{
		if (i == cmd->input[cmd->in_it])
		{
			//printf("[%d]\n", cmd->input[cmd->in_it]);
			/* if (!ft_strncmp(cmd->args[i], "<<", 2))
				ft_dinput(cmd, i); */
			ft_input(cmd, i);
			cmd->in_it++;
		}
		else if (i == cmd->output[cmd->out_it])
		{
			//printf("[%d]\n", cmd->output[cmd->out_it]);
			/* if (!ft_strncmp(cmd->args[i], ">>", 2))
				ft_doutput(cmd, i); */
			ft_output(cmd, i);
			cmd->out_it++;
		}
	}
}


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
	dup2(fd, STDIN_FILENO);
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
	dup2(fd, STDOUT_FILENO);
}
