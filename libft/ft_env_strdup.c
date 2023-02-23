/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:50 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/23 15:47:21 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_env_strdup(char **str)
{
	char	**aux;
	int		i;

	i = -1;
	while (str[++i])
	{
		if (!ft_strncmp(str[i], "OLDPWD=", 7))
		{
			aux = (char **)malloc(sizeof(char *) * (ft_doublestrlen(str) + 1));
			if (!aux)
				return (NULL);
			i = -1;
			while (str[++i])
				aux[i] = ft_strdup(str[i]);
			aux[i] = NULL;
			return (aux);
		}
	}
	aux = (char **)malloc(sizeof(char *) * (ft_doublestrlen(str)));
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
