/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:42 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/24 10:10:02 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_cmd	*args, char **cmd, int open)
{
	int		i;
	int		flag;
	pid_t	pid;

	i = 1;
	flag = 0;
	if (open)
	{
		pid = fork();
		if (pid == 0)
		{
			open_fd(args);
			ft_echo(args, cmd, 0);
			exit (0);
		}
		waitpid(pid, NULL, 0);
		return (0);
	}
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
