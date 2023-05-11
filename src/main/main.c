/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:46 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/05/11 07:28:26 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	g_sig_exit;

/**
 * @brief This function defines the order in which the minishell is executed.
 * 
 * @param args Command info structure.
 * @param env Enviroment of minishell.
 * @param prompt Commands from the prompt.
 */
void	ft_choped(t_cmd *args, t_env *env, char *prompt)
{
	char	*aux;

	aux = prompt;
	args->env = env;
	args = ft_memset(args, 0, sizeof(t_cmd));
	add_history(aux);
	if (get_data(args, aux, 0) == -1)
	{
		free(prompt);
		return ;
	}
	get_token(args, aux);
	if (g_sig_exit)
		env->exit_value = g_sig_exit;
	get_inter(args, env);
	if (*args->args)
		ft_selector(args, env);
	free_args(args);
}

/**
 * @brief Main function of Minishell.
 * 
 * @param argc Nb of arguments.
 * @param argvCcontent of the arguments (prompt received).
 * @param envp Original enviroment to be copied.
 * @return int 
 */
int	main(int argc, char **argv, char **envp)
{
	t_env	env;
	t_cmd	args;
	char	*prompt;
	int		stdio[2];

	init_shell(&args, &env, envp, stdio);
	while (1 && argc && argv)
	{
		prompt = readline("MiniHell=▸");
		resetstdio(stdio);
		if (!prompt)
			break ;
		if (!ft_isnot_empty_str(prompt))
		{
			free(prompt);
			continue ;
		}
		if (ft_check_prompt(&env, prompt))
			return (1);
		ft_choped(&args, &env, prompt);
		g_sig_exit = 0;
	}
	ft_doublefree(env.env);
	free(env.oldpwd);
	return (0);
}
