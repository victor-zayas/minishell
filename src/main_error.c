/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:17:08 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/27 21:58:26 by jaizpuru         ###   ########.fr       */
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

int	ft_check_prompt(char *prompt)
{
	if (ft_chr_in_set(';', prompt) || !ft_strncmp(prompt, "||", 2)
		|| !ft_strncmp(prompt, "&&", 2) || ft_chr_in_set('*', prompt))
		return (free(prompt),
			ft_putstr_fd("syntax error: special character\n", 2), 1);
	else
		return (0);
}

int	check_pipe_error(t_cmd	*cmd, t_env	*env, int pipe_end)
{
	if (!ft_strncmp(cmd->args[pipe_end], "|", 1)
		&& cmd->args[pipe_end + 1] == NULL)
	{
		ft_doublefree(cmd->cmd);
		free(cmd->atrb);
		return (1);
	}
	else if (!ft_strncmp(cmd->args[pipe_end], "|", 1)
		&& !ft_strncmp(cmd->args[pipe_end + 1], "|", 1))
	{
		ft_doublefree(cmd->cmd);
		free(cmd->atrb);
		pipe_error(cmd, env);
		return (1);
	}
	else
		return (0);
}
