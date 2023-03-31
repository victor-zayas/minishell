/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:30:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/31 10:07:09 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd(t_cmd	*cmd)
{
	cmd->cmd = (char **)malloc(sizeof(char *) * (find_sp(cmd->args, 0) + 1));
	if (!find_pipe(cmd->args, 0))
	{
		cmd->flag = 1;
		return (free(cmd->cmd));
	}
	if (!cmd->args[find_pipe(cmd->args, 0)])
		return ;
	cmd->atrb = (char **)malloc(sizeof(char *)
			* (find_sp(cmd->args, (find_sp(cmd->args, 0) + 1) + 1))
			- (find_sp(cmd->args, 0) + 1) + 1);
	if (!cmd->atrb)
		return ;
}

int	exec_cmd(t_cmd	*cmd, t_env	*env)
{
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		open_fd(cmd);
		exec(cmd->cmd, env);
	}
	wait(&i);
	return (WEXITSTATUS(i));
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
		exit (2);
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
	int	i;
	int	check;

	i = -1;
	cmd->flag = 0;
	check = 0;
	init_cmd(cmd);
	if (cmd->flag)
		return (pipe_error(cmd, env));
	while (cmd->args[++i])
	{
		if (!ft_strncmp(cmd->args[i], "|", 1) && i > 0)
			return (ft_pipe(cmd, env, i, check));
		else if (!ft_strncmp(cmd->args[i], ">", 1)
			|| !ft_strncmp(cmd->args[i], "<", 1))
			i = ft_redir(i, cmd->args, cmd, &check);
		else
			cmd->cmd[i] = ft_stephen_jokin(cmd, i);
	}
	close_str(cmd->cmd, i, check);
	if (ft_builtings(cmd->cmd, cmd, env, 1) == 1)
		env->exit_value = exec_cmd(cmd, env);
	ft_doublefree(cmd->cmd);
}
