/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:38:01 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/12 10:08:46 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	loop;
	size_t	in_loop;
	size_t	needle_len;
	char	*result;

	loop = 0;
	result = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (needle_len == 0 || haystack == needle)
		return (result);
	while (len > loop && result[loop])
	{
		in_loop = 0;
		while (result[loop + in_loop] && needle[in_loop]
			&& result[loop + in_loop] == needle[in_loop]
			&& len > loop + in_loop)
		{
			in_loop++;
		}
		if (in_loop == needle_len)
			return (result + loop);
		loop++;
	}
	return (0);
}
