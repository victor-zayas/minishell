/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:30:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/23 13:27:09 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_cmd(t_cmd	*cmd)
{
	cmd->cmd = (char **)malloc(sizeof(char *) * (find_pipe(cmd->args, 0) + 1));
	if (!cmd->cmd)
		return ;
	if (!cmd->args[find_pipe(cmd->args, (find_pipe(cmd->args, 0)))])
	{
		cmd->flag = 1;
		return ;
	}
	cmd->atrb = (char **)malloc(sizeof(char *)
			* (find_pipe(cmd->args, (find_pipe(cmd->args, 0) + 1) + 1))
			- (find_pipe(cmd->args, 0) + 1) + 1);
	if (!cmd->atrb)
		return ;
}

int	exec_cmd(t_cmd	*cmd, t_env	*env, char	**args)
{
	char	**path;
	char	*aux;
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		i = 0;
		open_fd(cmd);
		aux = ft_path(env->env);
		if (!aux)
		{
			if (execve(*args, args, NULL) == -1)
				exit(error_code(*args, env));
			exit(error_code(*args, env));
		}
		path = ft_split(aux, ':');
		free (aux);
		while (path[i] != NULL)
		{
			aux = ft_strjoin(path[i], "/");
			if (access(*args, X_OK) == 0)
			{
				free(aux);
				aux = ft_strdup(*args);
				break ;
			}
			else
			{
				free (path[i]);
				path[i] = ft_strjoin(aux, *args);
			}
			free (aux);
			aux = ft_strdup(path[i++]);
			if (access(aux, X_OK) == 0)
				break ;
			free (aux);
		}
		if (aux && path[i] && !access(aux, X_OK))
			execve(aux, args, env->env);
		exit (error_code(*args, env));
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
	check = 0;
	init_cmd(cmd);
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
	if (*cmd->cmd && !ft_strncmp(*cmd->cmd, "|", 1) && ft_strlen(*cmd->cmd) == 1)
		return (pipe_error(cmd, env));
	else if (check)
		cmd->cmd[check] = NULL;
	else
		cmd->cmd[i] = NULL;
	if (ft_builtings(cmd->cmd, cmd, env, 1) == 1)
		env->exit_value = exec_cmd(cmd, env, cmd->cmd);
	ft_doublefree(cmd->cmd);
}
