/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:25:36 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/27 17:52:46 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtings(t_cmd	*args, t_env *env, int i)
{
	int	flag;

	flag = ;
	while (args->cmd[i])
	{
		if (ft_strncmp(args->args[i], "pwd", 3) == 0)
			ft_pwd();
		else if (ft_strncmp(args->args[i], "env", 3) == 0)
			ft_env(env);
		else if (ft_strncmp(args->args[i], "echo", 4) == 0)
			ft_echo(args);
		else if (ft_strncmp(args->args[i], "exit", 4) == 0)
			ft_exit(args);
		else if (ft_strncmp(args->args[i], "cd", 2) == 0)
			ft_cd(args, env);
/* 		else if (ft_strncmp(args->args[i], "export", 6) == 0 || flag > i)
		{
			ft_export(env, args->args[flag]);
			flag++;
		} */
/* 		else if (ft_strncmp(args->args[i], "unset", 5) == 0)
		{
			ft_unset(env, args->args[flag]);
			flag++;
		} */
		else
			return (1);
	}
	return (0);
}
