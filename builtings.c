/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:25:36 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/23 19:15:27 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtings(t_cmd	*args, t_env *env, int i)
{
	if (!args->args[i])
		return (1);
	else if (ft_strncmp(args->args[i], "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(args->args[i], "env", 3) == 0)
		ft_env(env);
	else if (ft_strncmp(args->args[i], "echo", 4) == 0)
		ft_echo(args);
	else if (ft_strncmp(args->args[i], "exit", 4) == 0)
		ft_exit(args);
	else if (ft_strncmp(args->args[i], "cd", 2) == 0)
		ft_cd(args, env);
	else if (ft_strncmp(args->args[i], "export", 6) == 0)
		ft_export(env, args->args[i]);
	else if (ft_strncmp(args->args[i], "unset", 5) == 0)
		ft_unset(env, args->args[i]);
	else
		return (1);
	return (0);
}
