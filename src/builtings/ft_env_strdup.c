/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:50 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/05/11 06:49:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_env_aux(char	**str)
{
	int		i;
	char	**aux;

	aux = (char **)malloc(sizeof(char *) * (ft_doublestrlen(str) + 1));
	if (!aux)
		return (NULL);
	i = -1;
	while (str[++i])
		if (ft_strncmp(str[i], "OLDPWD=", 7))
			aux[i] = ft_strdup(str[i]);
	aux[i] = NULL;
	return (aux);
}

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
	aux = ft_env_aux(str);
	return (aux);
}
