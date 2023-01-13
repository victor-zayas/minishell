/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:46 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/01/13 13:25:00 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	ft_chopeadito(char	*prompt, char	**env, t_cmd	*args)
{
	char		*aux;

	aux = prompt;
	// get_data
	args->quotes = get_quotes(args, aux);
	args->double_quotes = get_double_quotes(args, aux);
	args->pipes = get_pipes(args, aux);
	// get_token
	get_token(args, aux);
	// print
	print(args);
	// get_cmd
	// exec(args, env);
	// get_history
	add_history(aux);
	env = 0;
	free_args(args);
	free(prompt);
}

void	my_signal(int sig)
{
	if (sig == 2)
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		//rl_redisplay();
	}
	else if (sig == 3)
	{
		rl_redisplay();
	}
	return ;
}

int	main(int argc, char **argv, char	**env)
{
	t_cmd		args;
	char	*prompt;

	init_args(&args);
	signal(SIGINT, my_signal);
	signal(SIGQUIT, my_signal);
	while (1 && argc && argv)
	{
		prompt = readline("Shootgun =>");
		if (!prompt)
			break ;
		if (!prompt[0])
			continue ;
		ft_chopeadito(prompt, env, &args);
	}
	return (0);
}
