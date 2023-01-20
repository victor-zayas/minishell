/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hedgedog <hedgedog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:46 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/01/20 15:08:35 by hedgedog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	print(t_cmd	*cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("\n				ARGS INSIDE THE STRUCTURE:\n");
	while(cmd->args[i])
		printf("				ARG N.%d ->> [%s]\n", j++, cmd->args[i++]);
	printf("\n				\n");
	printf("\n				DATA INSIDE THE STRUCTURE:\n");
	printf("				Clean words		: %d\n", cmd->words);
	printf("				Quotes	   		: %d\n", cmd->quotes);
	printf("				Double quotes	: %d\n", cmd->double_quotes);
	printf("				Pipes			: %d\n", cmd->pipes);
	printf("				Output Redirect	: %d\n", cmd->greater);
	printf("				Input Redirect	: %d\n", cmd->lesser);
}

void	ft_chopeadito(t_cmd	*args, char	*prompt)
{
	char		*aux;

	aux = prompt;
	init_args(args);
	get_data(args, aux);
	get_token(args, aux);
	print(args);
	// exec(args, env);
	add_history(aux);
	free_args(args);
	free(prompt);
}

void	my_signal()
{
		write(1, "Shootgun=▸  ", 15);
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
}

// int	main(int argc, char **argv, char	**env)
int	main(int argc, char **argv)
{
	t_cmd		args;
	char	*prompt;

	init_args(&args);
	signal(SIGINT, my_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1 && argc && argv)
	{
		prompt = readline("Shootgun=▸");
		if (!prompt)
			break ;
		if (!prompt[0])
			continue ;
		ft_chopeadito(&args, prompt);
		// ft_chopeadito(&args, prompt, env);
	}
	return (0);
}
