/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:42:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/12 12:07:03 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				loop;
	unsigned int	box;
	int				negative;

	box = 0;
	loop = 0;
	negative = 1;
	while (str[loop] == '\n' || str[loop] == '\t' || str[loop] == '\v'
		|| str[loop] == ' ' || str[loop] == '\f' || str[loop] == '\r')
			loop++;
	if (str[loop] == '-' || str[loop] == '+')
	{
		if (str[loop++] == '-')
		{
			negative = -negative;
		}
	}
	while (str[loop] >= '0' && str[loop] <= '9')
	{
		box = (box * 10) + str[loop] - '0';
		loop++;
	}
	return ((int)(box * negative));
}

/* int	main(void)
{
	char	str[6] = "30000";

	printf("%d", ft_atoi(str));
	return (0);
} */
