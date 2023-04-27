/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:30:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/27 16:30:42 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmd(t_cmd	*cmd, t_env	*env)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (cmd->args[i])
	{
		if (!ft_strncmp(cmd->args[i], "|", 1))
			return (ft_pipe(cmd, env, i, len), -1);
		else if (!ft_strncmp(cmd->args[i], ">", 1)
			|| !ft_strncmp(cmd->args[i], "<", 1))
			i = ft_redir(i, cmd->args, cmd);
		else
			cmd->cmd[len++] = ft_stephen_jokin(cmd, i);
		i++;
	}
	return (len);
}

char	*ft_stephen_jokin(t_cmd *cmd, int i)
{
	char	*aux;

	aux = ft_strdup(cmd->args[i]);
	return (aux);
}

int	ft_redir(int pos, char	**args, t_cmd	*cmd)
{
	if (!args[pos + 1])
	{
		write(2, "bash: syntax error near unexpected token `newline'\n", 52);
		return (-1);
	}
	if (!ft_strncmp(args[pos], ">", 2) || !ft_strncmp(args[pos], ">>", 3))
	{
		cmd->output[cmd->out_it] = pos + 1;
		cmd->out_it++;
	}
	if (!ft_strncmp(args[pos], "<", 2) || !ft_strncmp(args[pos], "<<", 3))
	{
		cmd->input[cmd->in_it] = pos + 1;
		cmd->in_it++;
	}
	pos++;
	return (pos);
}

void	ft_selector(t_cmd *cmd, t_env *env)
{
	int	len;

	cmd->flag = 0;
	len = 0;
	if (init_cmd(cmd, env)) // Error handling & Initialization
		return ;
	len = get_cmd(cmd, env); // Get command
	if (len == -1)
		return ;
	if (*cmd->cmd)
	{
		close_str(cmd->cmd, len, 0);
		if (ft_builtings(cmd->cmd, cmd, env, 1) == 1)
			env->exit_value = exec_cmd(cmd, env);
		if (*cmd->cmd && ft_strlen(*cmd->cmd) > 0)
			ft_doublefree(cmd->cmd);
		else if (cmd->cmd)
			free(cmd->cmd);
	}
}
