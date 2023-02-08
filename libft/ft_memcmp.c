/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:01:58 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/26 14:47:36 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	len;

	len = 0;
	while (len < n)
	{
		if (((unsigned char *)s1)[len] != ((unsigned char *)s2)[len])
			return (((unsigned char *)s1)[len] - ((unsigned char *)s2)[len]);
		len++;
	}
	return (0);
}
