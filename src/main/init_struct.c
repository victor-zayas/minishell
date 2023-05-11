/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:34:47 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/11 07:35:16 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern int	g_sig_exit;

/**
 * @brief There are a lot of things happening here:
 * 	1. Enviroment is copied with ft_env_strdup
 * 	2. OLDPWD variable is unset from the Enviroment, since it cannot appear
 * 	3. Some values of env structure are initialized to zero.
 * 	4. We use signal function to control signal behaviour
 * 	5. In case the global value is true, it means that a child process
 * 		has exited with that value.
 * 	6. We initialize the cmd structure with ft_memset
 * 	7. To be sure, we get the STDIN & STDOUT values inside a local two block
 * 	sized array, to be able to retrieve the values later on when changed.
 * 
 * @param cmd 
 * @param env 
 * @param envp 
 * @param stdio 
 */

void	init_shell(t_cmd *cmd, t_env *env, char	**envp, int *stdio)
{
	env->env = ft_env_strdup(envp);
	ft_unset(env, "OLDPWD");
	env->oldpwd = NULL;
	env->exit_value = 0;
	signal(SIGINT, my_signal);
	if (g_sig_exit)
		env->exit_value = g_sig_exit;
	signal(SIGQUIT, SIG_IGN);
	cmd = ft_memset(cmd, 0, sizeof(t_cmd));
	getstdio(stdio);
}
