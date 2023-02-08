/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:23:39 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/05/09 17:06:05 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		str_len;
	char	*pointer;
	char	*result;

	result = 0;
	pointer = (char *) s;
	str_len = 0;
	while (s[str_len])
	{
		if (s[str_len] == (unsigned char)c)
		{
			result = &pointer[str_len];
		}
		str_len++;
	}
	if (s[str_len] == (char)c)
	{
		result = &pointer[str_len];
	}
	return (result);
}
