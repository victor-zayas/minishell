/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:43:15 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/20 17:35:03 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char	**cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
		i++;
	if (i == 1)
		write(2, "exit\n", 5);
	i = 0;
	while (cmd[++i])
	{
		if (cmd[i] && !ft_isdigit(*cmd[i]))
		{
			write(2, "bash: exit: ", 13);
			write(2, cmd[i], ft_strlen(cmd[i]));
			write(2, ": numeric argument required\n", 29);
		}
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
