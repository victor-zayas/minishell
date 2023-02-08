/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:50:31 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/04/26 14:49:50 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s_len;
	char			*res;
	unsigned int	list1;
	unsigned int	list2;

	s_len = (ft_strlen(s1) + ft_strlen(s2));
	list1 = 0;
	list2 = 0;
	res = (char *)malloc((s_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (!s1 || !s2)
		return (NULL);
	while (s1[list1])
	{
		res[list1] = s1[list1];
		list1++;
	}
	while (s2[list2])
	{
		res[list1++] = s2[list2++];
	}
	res[list1] = '\0';
	return (res);
}
/*
int	main(void)
{
	char *s1 = "where is my ";
    char *s2 = "malloc ???";

	printf("%s", ft_strjoin(s2, s1));
} */
