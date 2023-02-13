/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bid_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:09 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/09 19:21:03 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bid_free(char **str)
{
	int	i;

	i = -1;
	while (str && str[++i])
	{
		if (str && str[i])
			free(str[i]);
	}
	if (str)
		free (str);
}
