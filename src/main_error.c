/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:17:08 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/24 17:21:20 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check_prompt(t_env	*env, char *prompt)
{
	if (ft_chr_in_set(';', prompt) || !ft_strncmp(prompt, "||", 2)
		|| !ft_strncmp(prompt, "&&", 2) || ft_chr_in_set('*', prompt))
		return (ft_doublefree(env->env), free(env->oldpwd), free(prompt),
			ft_putstr_fd("syntax error: special character\n", 2), 1);
	else
		return (0);
}
