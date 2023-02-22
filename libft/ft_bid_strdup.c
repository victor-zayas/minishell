/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bid_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:50 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/22 18:54:31 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_bid_strdup(char **str)
{
	char	**aux;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!ft_strncmp(str[i], "OLDPWD=", 7))
		{
			aux = (char **)malloc(sizeof(char *) * (ft_bid_strlen(str) + 1));
			if (!aux)
				return (NULL);
			i = -1;
			while (str[++i])
				aux[i] = ft_strdup(str[i]);
			aux[i] = NULL;
			return (aux);
		}
	}
	aux = (char **)malloc(sizeof(char *) * (ft_bid_strlen(str)));
	if (!aux)
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (ft_strncmp(str[i], "OLDPWD=", 7))
			aux[i] = ft_strdup(str[i]);
	}
	aux[i] = NULL;
	return (aux);
}
