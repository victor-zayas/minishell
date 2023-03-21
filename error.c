/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:50:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/21 19:50:51 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    pipe_error(t_cmd    *cmd, t_env *env)
{
    write(2, "bash: syntax error near unexpected token ", 42);
    write(2, *cmd->cmd, 1);
    write(2, "\n", 2);
    env->exit_value = 1;
    ft_doublefree(cmd->cmd);
    free(cmd->atrb);
    return ;
}