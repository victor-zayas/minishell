/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:25:36 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/01 17:21:19 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_builtings(t_cmd	*args, t_env *env)
{
	int	i;
	
	i = -1;
	while (args->args[++i])
	{
		if (ft_strncmp(args->args[i], "pwd", 3) == 0)
			ft_pwd();
		if (ft_strncmp(args->args[i], "env", 3) == 0)
			ft_env(env);
		if (ft_strncmp(args->args[i], "echo", 4) == 0)
			ft_echo(args);
	}
	
}
