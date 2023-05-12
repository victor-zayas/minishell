/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:25:36 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/05/11 06:49:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief	This function checks if argument from the prompt is a
 * 			valid word to exec the builtin.
 * 
 * @param str Returns int value if that string is a valid command.
 * @return int return (0) in case of true, 1 in false
 */
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

/**
 * @brief This funnction call the builtings, checking the length of names.
 * 
 * @param args Arguments received from prompt.
 * @param cmd Command constructed with prompt.
 * @param env Modified enviroment for get exit value.
 * @param open Int for checks field descriptor.
 * @return int 
 */
int	ft_builtings(char	**args, t_cmd	*cmd, t_env *env, int open)
{
	if (ft_checker(*args))
		return (1);
	if (ft_strncmp(*args, "pwd", 3) == 0)
		env->exit_value = ft_pwd(cmd, open);
	else if (ft_strncmp(*args, "env", 3) == 0)
		env->exit_value = ft_env(cmd, env, open);
	else if (*args && ft_strncmp(*args, "echo", 4) == 0)
		env->exit_value = ft_echo(cmd, args, open);
	else if (*args && ft_strncmp(*args, "exit", 4) == 0)
		env->exit_value = ft_exit(cmd, args, open);
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
