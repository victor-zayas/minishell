/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:30:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/29 18:29:56 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd(t_cmd	*cmd)
{
	cmd->cmd = (char **)malloc(sizeof(char *) * (find_sp(cmd->args, 0) + 1));
	if (!cmd->cmd)
		return ;
	if (!cmd->args[find_pipe(cmd->args, 0)])
		return ;
	cmd->atrb = (char **)malloc(sizeof(char *)
			* (find_sp(cmd->args, (find_sp(cmd->args, 0) + 1) + 1))
			- (find_sp(cmd->args, 0) + 1) + 1);
	if (!cmd->atrb)
		return ;
}

char	*ft_stephen_jokin(t_cmd *cmd, int i)
{
	char	*aux;

	aux = ft_strdup(cmd->args[i]);
	return (aux);
}

int	ft_redir(int pos, char	**args, t_cmd	*cmd, int	*checker)
{
	*checker = pos;
	if (!args[pos + 1])
	{
		write(2, "bash: syntax error near unexpected token ", 42);
		write(2, args[pos], 1);
		write(2, "\n", 2);
		*checker = -1;
		return (pos);
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
	pid_t	pid;
	int		rt;
	int		i;
	int		check;

	i = -1;
	check = 0;
	if (*cmd->args && !ft_strncmp(*cmd->args, "|", 1)
		&& ft_strlen(*cmd->args) == 1)
		return (pipe_error(cmd, env));
	init_cmd(cmd);
	while (check != -1 && cmd->args[++i])
	{
		if (!ft_strncmp(cmd->args[i], "|", 1) && i > 0)
			return (ft_pipe(cmd, env, i, check));
		else if (!ft_strncmp(cmd->args[i], ">", 1)
			|| !ft_strncmp(cmd->args[i], "<", 1))
			i = ft_redir(i, cmd->args, cmd, &check);
		else
			cmd->cmd[i] = ft_stephen_jokin(cmd, i);
	}
	if (check == -1)
	{
		cmd->cmd[i] = NULL;
		ft_doublefree(cmd->cmd);
		return ;
	}
	else if (check)
		cmd->cmd[check] = NULL;
	else
		cmd->cmd[i] = NULL;
	if (ft_builtings(cmd->cmd, cmd, env, 1) == 1)
	{
		pid = fork();
		if (pid == 0)
			exec(cmd->cmd, env);
		waitpid(pid, &rt, 0);
		rt = WEXITSTATUS(rt);
		env->exit_value = rt;
	}
	ft_doublefree(cmd->cmd);
}
