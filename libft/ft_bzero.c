/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:40:20 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/07 16:39:25 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*content;
	size_t	number2;

	content = (char *)s;
	number2 = 0;
	while (n > number2)
	{
		content[number2] = 0;
		number2++;
	}
}
