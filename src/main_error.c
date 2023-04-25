/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:17:08 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/25 16:46:25 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	ft_check_prompt(t_env	*env, char *prompt)
{
	if (ft_chr_in_set(';', prompt) || !ft_strncmp(prompt, "||", 2)
		|| !ft_strncmp(prompt, "&&", 2) || ft_chr_in_set('*', prompt))
		return (ft_doublefree(env->env), free(env->oldpwd), free(prompt),
			ft_putstr_fd("syntax error: special character\n", 2), 1);
	else
		return (0);
}
