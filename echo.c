/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:42 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/01 15:50:16 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd *args)
{
	int	i;
	int	flag;

	i = 1;
	flag = 0;
	if (args->args[i] && !ft_strncmp(args->args[1], "$", 1)
		&& ft_strlen(args->args[1]) > 1)
	{
		printf("\n");
		return ;
	}
	else if (args->args[i] && !ft_strncmp(args->args[1], "-n", 2))
	{
		i++;
		flag = 1;
	}
	while (args->args[i])
	{
		printf("%s", args->args[i]);
		i++;
	}
	if (!flag)
		printf("\n");
}
