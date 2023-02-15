/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bid_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:50 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/13 18:40:57 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_bid_strdup(char **str)
{
	char	**aux;
	int		i;

	i = -1;
	aux = (char **)malloc(sizeof(char *) * (ft_bid_strlen(str) + 1));
	if (!aux)
		return (NULL);
	while (str[++i])
		aux[i] = ft_strdup(str[i]);
	aux[i] = NULL;
	return (aux);
}
