/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:38:39 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/11 06:49:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	getstdio(int *stdio)
{
	stdio[0] = dup(STDIN_FILENO);
	stdio[1] = dup(STDOUT_FILENO);
}

void	resetstdio(int *stdio)
{
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
}
