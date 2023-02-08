/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:51:21 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/26 13:36:56 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*content;
	char	*content2;
	size_t	loop;

	loop = 0;
	content = (char *)src;
	content2 = (char *)dst;
	if (!dst && !src)
		return (NULL);
	while (n > loop)
	{
		content2[loop] = content[loop];
		loop++;
	}
	return (dst);
}
