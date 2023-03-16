/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:30:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/16 15:14:38 by jaizpuru         ###   ########.fr       */
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
			* (find_pipe(cmd->args, (find_pipe(cmd->args, 0) + 1)) + 1));
	if (!cmd->atrb)
		return ;
}

int		exec_cmd(t_cmd	*cmd, t_env	*env)
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
		aux = ft_path(env->env);
		if (!aux)
		{
			if (execve(*cmd->cmd, cmd->cmd, NULL) == -1)
				exit(error_code(*cmd->cmd, env));
			exit(error_code(*cmd->cmd, env));
		}
		path = ft_split(aux, ':');
		free (aux);
		while (path[i] != NULL)
		{
			aux = ft_strjoin(path[i], "/");
			if (access(*cmd->cmd, X_OK) == 0)
			{
				free(aux);
				aux = ft_strdup(*cmd->cmd);
				break ;
			}
			else
			{
				free (path[i]);
				path[i] = ft_strjoin(aux, *cmd->cmd);
			}
			free (aux);
			aux = ft_strdup(path[i++]);
			if (access(aux, X_OK) == 0)
				break ;
			free (aux);
		}
		if (aux && path[i] && !access(aux, X_OK))
			execve(aux, cmd->cmd, env->env);
		exit (error_code(*cmd->cmd, env));
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
		{
			cmd->cmd[i] = NULL;
			while (cmd->args[++i] && ft_strncmp(cmd->args[i], "|", 1))
				cmd->atrb[check++] = ft_stephen_jokin(cmd, i);
			cmd->atrb[check] = NULL;
			ft_pipe(cmd, env, i);
			ft_doublefree(cmd->atrb);
			ft_doublefree(cmd->cmd);
			return ;
		}
		else if (!ft_strncmp(cmd->args[i], ">", 1)
			|| !ft_strncmp(cmd->args[i], "<", 1))
		{
			if (!cmd->args[i + 1])
			{
				write(2, "bash: syntax error near unexpected token ", 42);
				write(2, cmd->args[i], 1);
				write(2, "\n", 2);
				exit (2);
			}
			if (!ft_strncmp(cmd->args[i], ">", 1))
				ft_output(cmd, i + 1);
			if (!ft_strncmp(cmd->args[i], "<", 1))
				ft_input(cmd, i + 1);
			i++;
		}
		else
			cmd->cmd[i] = ft_stephen_jokin(cmd, i);
	}
	if (check)
		cmd->cmd[check] = NULL;
	else
		cmd->cmd[i] = NULL;
	if (!ft_strncmp(*cmd->cmd, "|", 1) && ft_strlen(*cmd->cmd) == 1)
	{
		write(2, "bash: syntax error near unexpected token ", 42);
		write(2, *cmd->cmd, 1);
		write(2, "\n", 2);
		exit (1);
	}
	if (ft_builtings(cmd->cmd, cmd, env) == 1)
		env->exit_value = exec_cmd(cmd, env);
	ft_doublefree(cmd->cmd);
}
