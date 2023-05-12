/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:09:44 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 12:18:06 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief This function closes an open portion of the prompt that
 * 		has been cut to store a dollar token previously.
 * 
 * @param str A one-sided [open]double quote content inside prompt.
 * @return char* A closed double quote token.
 */
char	*ft_append_left_side(char	*str)
{
	char	*aux;
	int		i;

	i = 0;
	if (ft_strlen(str) == 1 && *str == '"')
		return (free(str), ft_strdup(""));
	aux = malloc(sizeof(char) * (ft_strlen(str) + 2));
	aux[0] = '"';
	while (str[i])
	{
		aux[i + 1] = str[i];
		i++;
	}
	free(str);
	return (aux);
}

/**
 * @brief This function closes a dollar token by both sides with double quotes.
 * 
 * @param str A dollar token string.
 * @return char* A closed double quote dollar token.
 */
char	*ft_append_both_sides(char	*str)
{
	char	*aux;
	int		i;

	i = 0;
	if (ft_strlen(str) == 1 && *str == '"')
		return (free(str), ft_strdup(""));
	aux = malloc(sizeof(char) * (ft_strlen(str) + 3));
	aux[0] = '"';
	while (str[i])
	{
		aux[i + 1] = str[i];
		i++;
	}
	aux[i + 1] = '"';
	free(str);
	return (aux);
}
