/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:43:15 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/24 13:04:00 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_digit(char	**cmd, int i)
{
	while (cmd[++i])
	{
		if (cmd[i] && !ft_isdigit(*cmd[i]))
		{
			write(2, "bash: exit: ", 13);
			write(2, cmd[i], ft_strlen(cmd[i]));
			write(2, ": numeric argument required\n", 29);
			return (1);
		}
	}
	return (0);
}

int	exit_fd(t_cmd	*args, char	**cmd, int open)
{
	pid_t	pid;
	int		flag;

	if (open)
	{
		pid = fork();
		if (pid == 0)
		{
			if (open_fd(args))
				exit (1);
			exit(ft_exit(args, cmd, 0));
		}
		waitpid(pid, &flag, 0);
		return (WEXITSTATUS(flag));
	}
	return (0);
}

int	ft_exit(t_cmd	*args, char **cmd, int open)
{
	int		i;

	i = 0;
	if (open)
		exit (exit_fd(args, cmd, open));
	if (check_digit(cmd, i))
		return (2);
	while (cmd[i])
		i++;
	if (i == 1)
	{
		write(2, "exit\n", 5);
		exit (0);
	}
	if (i == 2)
		exit(ft_atoi(cmd[1]));
	if (i > 2)
	{
		write(2, "exit\n", 5);
		write(2, "bash: exit: too many arguments\n", 32);
		return (1);
	}
	return (0);
}
