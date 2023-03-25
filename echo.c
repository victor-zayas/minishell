/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:42 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/25 11:47:16 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_open(t_cmd *args, char **cmd, int open)
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
			exit(ft_echo(args, cmd, 0));
		}
		waitpid(pid, &flag, 0);
		return (WEXITSTATUS(flag));
	}
	return (0);
}

int	ft_echo(t_cmd *args, char **cmd, int open)
{
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	if (open)
		return (check_open(args, cmd, open));
	if (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
	{
		flag += 1;
		i++;
	}
	while (cmd[i])
	{
		if (cmd[i] && !ft_strncmp(cmd[i], "-n", 2) && flag == 1)
			i++;
		else if ((i > 1))
			printf(" %s", cmd[i++]);
		else
			printf("%s", cmd[i++]);
	}
	if (!flag)
		printf("\n");
	return (0);
}
