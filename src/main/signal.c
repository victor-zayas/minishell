/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:42:24 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/03 08:43:59 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_sig_exit;

/**
 * @brief This function rewrite the prompt
 * 		  with signals that interrupt the process.
 * 
 * @param sig Int of signal to be printed in prompt.
 */
void	cut_stdio(int sig)
{
	char	n;

	n = sig + '0';
	write(1, "Quit: ", 7);
	write(1, &n, 1);
	write(1, "\n", 2);
}

/**
 * @brief This function rewrite the prompt with new line.
 * 
 * @param sig Int of signal to replace prompt.
 */
void	my_signal(int sig)
{
	if (sig == 2)
	{
		printf("\b\b\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_sig_exit = 130;
	}
}
