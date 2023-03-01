/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:36:29 by becastro          #+#    #+#             */
/*   Updated: 2023/02/28 23:14:42 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief
 * Takes an unsigned char as string an returns (1) if is blank or (0) if is not
 * @param c
 * @return int
 */
int	ft_isspace(unsigned char c)
{
	if ((c == ' ' || c == '\t' || c == '\f'
			|| c == '\r' || c == '\n' || c == '\v'))
		return (1);
	return (0);
}
