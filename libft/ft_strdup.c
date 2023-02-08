/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 11:48:24 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/11 12:01:33 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cop_s1;
	int		num;

	num = 0;
	len = ft_strlen(s1);
	cop_s1 = (char *)malloc(len + 1);
	if (!cop_s1)
		return (NULL);
	while (s1[num])
	{
		cop_s1[num] = (char)s1[num];
		num++;
	}
	cop_s1[num] = '\0';
	return (cop_s1);
}
