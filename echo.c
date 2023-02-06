/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:42 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/06 18:10:23 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_cmd *args)
{
	int	i;

	i = 1;
	if (!strncmp(args->args[1], "-n", 2))
		i++;
	while (args->args[i])
	{
		printf("%s", args->args[i]);
		i++;
	}
	if (strncmp(args->args[1], "-n", 2))
		printf("\n");
}
