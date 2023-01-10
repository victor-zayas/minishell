/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:01:00 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/07 16:38:35 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*content;
	int				number2;
	unsigned char	convert;

	content = (char *)b;
	number2 = 0;
	convert = c - '0';
	while (len > 0)
	{
			content[number2] = convert + '0';
			len--;
			number2++;
	}
	return (content);
}
