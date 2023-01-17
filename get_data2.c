/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:10:47 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/17 12:13:35 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_lesser(char	*prompt)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == ('<'))
			checker++;
		i++;
	}
	return (checker);
}

int	get_greater(char	*prompt)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == ('>'))
			checker++;
		i++;
	}
	return (checker);
}