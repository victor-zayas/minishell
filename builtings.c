/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:25:36 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/21 18:42:42 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_checker(char	*str)
{
	if (!str)
		return (1);
	if (ft_strncmp(str, "pwd", 3) == 0)
		return (0);
	else if (ft_strncmp(str, "env", 3) == 0)
		return (0);
	else if (str && ft_strncmp(str, "echo", 4) == 0)
		return (0);
	else if (str && ft_strncmp(str, "exit", 4) == 0)
		return (0);
	else if (str && ft_strncmp(str, "cd", 2) == 0)
		return (0);
	else if (str && ft_strncmp(str, "export", 6) == 0)
		return (0);
	else if (str && ft_strncmp(str, "unset", 5) == 0)
		return (0);
	return (1);
}

int	ft_builtings(char	**args, t_cmd	*cmd, t_env *env)
{
	pid_t	pid;
	int		i;

	pid = fork();
	i = 0;
	if (pid == -1)
		perror("fork");
	else if (pid == 0)
	{
		if (ft_checker(*args))
			exit (1);
		open_fd(cmd);
		if (ft_strncmp(*args, "pwd", 3) == 0)
			env->exit_value = ft_pwd();
		else if (ft_strncmp(*args, "env", 3) == 0)
			env->exit_value = ft_env(env);
		else if (*args && ft_strncmp(*args, "echo", 4) == 0)
			env->exit_value = ft_echo(args);
		else if (*args && ft_strncmp(*args, "exit", 4) == 0)
			env->exit_value = ft_exit(args);
		else if (*args && ft_strncmp(*args, "cd", 2) == 0)
			env->exit_value = ft_cd(args, cmd, env);
		else if (*args && ft_strncmp(*args, "export", 6) == 0)
			env->exit_value = ft_export(env, *(args + 1), *args);
		else if (*args && ft_strncmp(*args, "unset", 5) == 0)
			env->exit_value = ft_unset(env, *(args + 1));
		exit (0);
	}
	wait(&i);
	return (WEXITSTATUS(i));
}
