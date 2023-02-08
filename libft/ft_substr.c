/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 10:20:03 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/29 12:22:54 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (0);
	if (ft_strlen(s) > len + start)
		str = malloc((len + 1) * sizeof(char));
	else if (ft_strlen(s) > start)
		str = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		str = malloc(sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = start;
	if (start < ft_strlen(s))
	{
		while (s[i] && (i < len) && (j < ft_strlen(s)))
			str[i++] = s[j++];
	}
	str[i] = '\0';
	return (str);
}
