/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:42 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/02 20:49:52 by jaizpuru         ###   ########.fr       */
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
	else if (args->args[i] && !ft_strncmp(args->args[i], "-n", 2))
	{
		i++;
		flag = 1;
	}
	while (args->args[i])
	{
		if (!ft_strncmp(args->args[i], "-n", 2))
			i++;
		else
			printf("%s", args->args[i++]);
	}
	if (!flag)
		printf("\n");
}
