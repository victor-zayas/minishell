/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:35:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/05/09 17:05:53 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		str_len;
	char	*pointer;

	pointer = (char *) s;
	str_len = 0;
	while (s[str_len])
	{
		if (s[str_len] == (unsigned char)c)
		{
			return (&pointer[str_len]);
		}
		str_len++;
	}
	if (s[str_len] == (char)c)
	{
		return (&pointer[str_len]);
	}
	return (NULL);
}
