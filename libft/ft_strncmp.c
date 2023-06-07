/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:30:45 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/07 11:04:19 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cast_s1;
	unsigned char	*cast_s2;
	size_t			pos;
	size_t			result;


	cast_s1 = (unsigned char *)s1;
	cast_s2 = (unsigned char *)s2;
	pos = 0;
	result = 0;
	if (n == 0)
		return (0);
	while ((cast_s1[pos] == cast_s2[pos] && cast_s1[pos] != '\0') && pos < n)
		pos++;
	if (pos == n)
		pos--;
	result = cast_s1[pos] - cast_s2[pos];

	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);


	return (result);
} */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	(void)n;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
