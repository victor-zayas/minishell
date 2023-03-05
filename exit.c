/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:43:15 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/05 11:14:57 by jaizpuru         ###   ########.fr       */
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
		write(1, "exit\n", 5);
	i = 0;
	while (cmd[i])
		i++;
	if (i > 2)
	{
		printf("Shootgun=▸ Too many arguments\n");
		return (0);
	}
	if (i == 1)
		exit(0);
	else if (i == 2)
		exit(ft_atoi(cmd[1]));
	return (0);
}
