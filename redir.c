/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:56:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/21 17:07:12 by jaizpuru         ###   ########.fr       */
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
	while (cmd->args[i] && (cmd->greater >= 1 || cmd->lesser >= 1
			|| cmd->double_in >= 1 || cmd->double_out >= 1))
	{
		if (cmd->input || cmd->output)
		{
			if (cmd->input && i == cmd->input[cmd->in_it])
			{
				ft_input(cmd, i);
				cmd->in_it++;
			}
			else if (cmd->output && i == cmd->output[cmd->out_it])
			{
				ft_output(cmd, i);
				cmd->out_it++;
			}
		}
		i++;
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
