/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:42 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/08 12:42:31 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(char **cmd)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (cmd[i] && !ft_strncmp(cmd[i], "$", 1)
		&& ft_strlen(cmd[i++]) > 1)
		printf("\n");
	else if (cmd[i] && !ft_strncmp(cmd[i++], "-n", 2))
		flag = 1;
	while (cmd[i])
	{
		if (!ft_strncmp(cmd[i], "-n", 2) && flag == 1)
			i++;
		else if ((i > 1))
			printf(" %s", cmd[i++]);
		else
			printf("%s", cmd[i++]);
	}
	if (!flag)
		printf("\n");
}
