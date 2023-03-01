/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:25:36 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/28 23:08:40 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtings(char	**args, t_cmd	*cmd, t_env *env)
{
	if (!*args)
		return (1);
	if (ft_strncmp(*args, "pwd", 3) == 0)
		ft_pwd();
	else if (ft_strncmp(*args, "env", 3) == 0)
		ft_env(env);
	else if (ft_strncmp(*args, "echo", 4) == 0)
		ft_echo(cmd);
	else if (ft_strncmp(*args, "exit", 4) == 0)
		ft_exit(cmd);
	else if (ft_strncmp(*args, "cd", 2) == 0)
		ft_cd(cmd, env);
	else if (ft_strncmp(*args, "export", 6) == 0)
		ft_export(env, *(++args));
	else if (ft_strncmp(*args, "unset", 5) == 0)
		ft_unset(env, *(++args));
	else
		return (1);
	return (0);
}
