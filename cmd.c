/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:30:48 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/02/16 20:29:12 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(char	**cmd, char	**enviroment)
{
	char	**path;
	int		i;
	pid_t	pid;

	i = 0;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (!cmd)
			return ;
		path = ft_split(ft_path(enviroment), ':');
		while (path[i])
		{
			path[i] = ft_strjoin(path[i], "/");
			path[i] = ft_strjoin(path[i], *cmd);
			execve(path[i], cmd, enviroment);
			i++;
		}
		perror("bash: command not found");
	}
	waitpid(pid, NULL, 0);;
	return ;
}

char	*ft_stephen_jokin(t_cmd	*cmd, char	*str, int	i)
{
	str = (char *)malloc(sizeof(ft_strlen(cmd->args[i]) + ft_strlen(str)) + 1);
	if (ft_strchr(cmd->args[i], '|') || ft_strchr(cmd->args[i], '<') 
		|| ft_strchr(cmd->args[i], '>'))
		return (NULL);
	str = ft_strjoin(str, cmd->args[i]);
	return (str);
}

void	ft_selector(t_cmd	*cmd, t_env	*env)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	cmd->cmd = (char **)malloc(sizeof(char *) * find_pipe(cmd->args, 0) + 1);
	if (!cmd->cmd)
		return ;
	cmd->atrb = (char **)malloc(sizeof(char *) * (find_pipe(cmd->args, find_pipe(cmd->args, 0))) + 2);
	if (!cmd->atrb)
		return ;
	while(cmd->args[++i])
	{
		if(!ft_strncmp(cmd->args[i], "|", 1))
		{
			//cmd->cmd[i] = ft_stephen_jokin(cmd, cmd->cmd[i], i);
			while (cmd->args[++i])
			{
				cmd->atrb[j] = ft_stephen_jokin(cmd, cmd->atrb[j], i);
				//printf("			ATR -> %s\n", cmd->atrb[j]);
				j++;
			}
			//cmd->atrb[i] = NULL;
			ft_fd(cmd, env);
			return ;
		}
		cmd->cmd[i] = ft_stephen_jokin(cmd, cmd->cmd[i], i);
		//printf("			CMD -> %s\n", cmd->cmd[i]);
	}
	exec_cmd(cmd->cmd, env->env);
	ft_bid_free(cmd->cmd);
}
