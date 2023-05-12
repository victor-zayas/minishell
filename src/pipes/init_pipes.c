/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:21:52 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/12 10:24:32 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_string_trader(t_cmd *cmd, int start)
{
	int	len;

	ft_doublefree(cmd->cmd);
	cmd->cmd = ft_doublestrdup(cmd->atrb);
	ft_doublefree(cmd->atrb);
	len = 0;
	while (cmd->args[start + len] && ft_strncmp(cmd->args[start + len], "|", 1)
		&& ft_strncmp(cmd->args[start + len], ">", 1)
		&& ft_strncmp(cmd->args[start + len], "<", 1))
		len += 1;
	cmd->atrb = (char **)malloc(sizeof(char *) * (len + 1));
	len = 0;
	while (cmd->args[start + len]
		&& ft_strncmp(cmd->args[start + len], "|", 1)
		&& ft_strncmp(cmd->args[start + len], ">", 1)
		&& ft_strncmp(cmd->args[start + len], "<", 1))
	{
		cmd->atrb[len] = ft_stephen_jokin(cmd, start + len);
		len++;
	}
	cmd->atrb[len] = NULL;
	return (len);
}

void	atrb_fill(t_cmd	*cmd, int pipe_pos, int block_pos)
{
	while (cmd->args[++pipe_pos] && ft_strncmp(cmd->args[pipe_pos], "|", 1))
	{
		if (!ft_strncmp(cmd->args[pipe_pos], ">", 1)
			|| !ft_strncmp(cmd->args[pipe_pos], "<", 1))
		{
			cmd->redir_end = block_pos;
			if (cmd->args[pipe_pos])
				pipe_pos += 1;
		}
		else
			cmd->atrb[block_pos++] = ft_stephen_jokin(cmd, pipe_pos);
	}
	cmd->pipe_pos = pipe_pos;
	cmd->block_pos = block_pos;
}

void	init_cmd_pipes(t_cmd	*cmd, int pipe_end, int sp_end)
{
	close_str(cmd->cmd, pipe_end, sp_end);
	while (cmd->args[pipe_end] && ft_strncmp(cmd->args[pipe_end], "|", 2))
		pipe_end++;
	if (!ft_strncmp(cmd->args[pipe_end], "|", 1)
		&& cmd->args[pipe_end + 1] == NULL)
	{
		ft_doublefree(cmd->cmd);
		free(cmd->atrb);
		return ;
	}
	atrb_fill(cmd, pipe_end, 0);
	close_str(cmd->atrb, cmd->block_pos, cmd->redir_end);
}
