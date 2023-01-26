/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:35:00 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/01/26 17:48:55 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_bid_strdup(char **str)
{
	char	**aux;
	int		i;

	i = -1;
	aux = (char **)malloc(sizeof(char*) * (ft_bid_strdup(str) + 1));
	if (!aux)
		return (NULL);
	while (str[++i])
		aux[i] = ft_strdup(str[i]);
	aux[i] = '\0';
	return (aux);	
}

int	ft_bid_strlen(char **str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_bid_free(char **str)
{
	int	i;
	
	i = -1;
	while (str && str[++i])
	{
		if (str && str[i])
			free(str[i]);
	}
	if (str)
		free (str);		
}
