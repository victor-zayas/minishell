/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:43:15 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/24 12:12:33 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_digit(char	**cmd, int i)
{
	while (cmd[++i])
	{
		if (cmd[i] && !ft_isdigit(*cmd[i]))
		{
			write(2, "bash: exit: ", 13);
			write(2, cmd[i], ft_strlen(cmd[i]));
			write(2, ": numeric argument required\n", 29);
		}
	}
}

void	exit_fd(t_cmd	*args, char	**cmd, int open)
{
	pid_t	pid;

	if (open)
	{
		pid = fork();
		if (pid == 0)
		{
			open_fd(args);
			ft_exit(args, cmd, 0);
			exit (0);
		}
		waitpid(pid, NULL, 0);
	}
}

int	ft_exit(t_cmd	*args, char **cmd, int open)
{
	int		i;

	i = 0;
	exit_fd(args, cmd, open);
	check_digit(cmd, i);
	while (cmd[i])
		i++;
	if (i == 1)
	{
		write(2, "exit\n", 5);
		exit (0);
	}
	if (i > 2)
	{
		write(2, "exit\n", 5);
		write(2, "bash: exit: too many arguments\n", 32);
		return (0);
	}
	if (i == 1)
		exit(0);
	else if (i == 2)
		exit(ft_atoi(cmd[1]));
	return (0);
}
