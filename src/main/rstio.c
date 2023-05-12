/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:38:39 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/11 11:15:11 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief	We get the STDIN & STDOUT values inside an array, just to be sure
 * 			we do not lose them.
 * 			(although we know they are ussualy 0 for STDIN & 1 for STDOUT).
 * 
 * @param stdio File Descriptor
 */
void	getstdio(int *stdio)
{
	stdio[0] = dup(STDIN_FILENO);
	stdio[1] = dup(STDOUT_FILENO);
}

/**
 * @brief	In this function, we reset the values of both STDIN & STDOUT to
 * 			start, it is used in case we use any redirection for
 * 			input/output purposes.
 * 
 * @param stdio File Descriptor
 */
void	resetstdio(int *stdio)
{
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
}
