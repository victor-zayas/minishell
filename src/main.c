/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:46 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/04/25 11:54:05 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_sig_exit;

void	ft_choped(t_cmd *args, t_env *env, char *prompt)
{
	char	*aux;

	aux = prompt;
	args->env = env;
	init_args(args);
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

void	cut_stdio(int sig)
{
	char	n;

	n = sig + '0';
	write(2, "Quit: ", 7);
	write(2, &n, 1);
	write(2, "\n", 2);
}

void	my_signal(int sig)
{
	if (sig == 2)
	{
		printf("\b\b\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_sig_exit = 130;
	}
}

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
