/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 15:35:38 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/03/27 16:00:13 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

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
