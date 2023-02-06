/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:43:15 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/06 17:59:33 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//no funca
int	ft_exit(t_cmd *args)
{
	int	i;

	i = 0;
	while(args->args[i])
		i++;
	args->n_cmd = i;
	if (args->size == 1)
		write(1, "exit\n", 5);
	i = 0;
	while (args->args[args->n_cmd])
		i++;
	if (i > 2)
	{
		printf("Shootgun=▸ Too many arguments\n");
		g_exit = 1;
		return (0);
	}
	if (args->n_cmd == 1)
	{
		free_args(args);
		g_exit = 0;
		exit(0);
	}
	return (0);
}
