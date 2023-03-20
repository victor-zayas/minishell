/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:25:36 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/20 17:47:28 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_builtings(char	**args, t_cmd	*cmd, t_env *env)
{
	if (!*args)
		return (1);
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
	else
		return (1);
	return (0);
}
