/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:20:34 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/07 16:38:22 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	length;

	length = 0;
	if (dstsize == 0)
	{
		return (ft_strlen(src));
	}
	while (dstsize > length + 1 && src[length])
	{
		dst[length] = src[length];
		length++;
	}
	dst[length] = '\0';
	return (ft_strlen(src));
}
