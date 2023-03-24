/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:50:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/24 15:06:06 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_error(t_cmd	*cmd, t_env	*env)
{
	write(2, "bash: syntax error near unexpected token ", 42);
	write(2, *cmd->args, 1);
	write(2, "\n", 2);
	env->exit_value = 1;
	return ;
}