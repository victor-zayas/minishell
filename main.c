/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:46 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/21 18:35:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_choped(t_cmd *args, t_env *env, char *prompt)
{
	char	*aux;

	aux = prompt;
	init_args(args);
	add_history(aux);
	if (get_data(args, aux) == -1)
	{
		free(prompt);
		return ;
	}
	get_token(args, aux);
	get_inter(args, env);
	//print(args);
	ft_selector(args, env);
	free_args(args);
}

void	my_signal(int sig)
{
	if (sig == 2)
	{
		write(1, "MiniHell=▸", 13);
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	env;
	t_cmd	args;
	char	*prompt;

	init_shell(&args, &env, envp);
	while (1 && argc && argv)
	{
		prompt = readline("MiniHell=▸");
		if (!prompt)
			break ;
		if (!prompt[0])
			continue ;
		if (!ft_isnot_empty_str(prompt))
			continue ;
		if (ft_chr_in_set(';', prompt))
			return (ft_doublefree(env.env), free(env.oldpwd),
				ft_putstr_fd("Syntax error BRO U ARE STUPID\n", 2), 1);
		ft_choped(&args, &env, prompt);
		
	}
	ft_doublefree(env.env);
	free(env.oldpwd);
	return (0);
}
