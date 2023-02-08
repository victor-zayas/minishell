/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 09:43:15 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/07 18:21:44 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		return (0);
	}
	if (args->n_cmd == 1)
	{
		free_args(args);
		exit(0);
	}
	return (0);
}
