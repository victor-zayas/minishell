/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:36 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/12 15:34:12 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_quotes(t_cmd	*args, char	*line)
{
	int	i;
	int	checker;

	checker = 0;
	args = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ('\''))
			checker += 1;
		i++;
	}
	if ((checker % 2) == 0 && checker != 0)
		return (2);
	else if ((checker % 2) == 1 && checker != 0)
		return (1);
	else
		return (0);
}

int	get_double_quotes(t_cmd	*args, char	*line)
{
	int	i;
	int	checker;

	checker = 0;
	args = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ('"'))
			checker += 1;
		i++;
	}
	if ((checker % 2) == 0 && checker != 0)
		return (2);
	else if ((checker % 2) == 1 && checker != 0)
		return (1);
	else
		return (0);
}

int	get_pipes(t_cmd	*args, char	*line)
{
	int	i;
	int	checker;

	checker = 0;
	args = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ('|'))
			checker += 1;
		i++;
	}
	if ((checker % 2) == 0 && checker != 0)
		return (2);
	else if ((checker % 2) == 1 && checker != 0)
		return (1);
	else
		return (0);
}
