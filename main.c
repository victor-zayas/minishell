/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:46 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/27 17:13:44 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void print(t_cmd *cmd)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("\n				ARGS INSIDE THE STRUCTURE:\n");
	while (cmd->args[i])
		printf("				ARG N.%d ->> [%s]\n", j++, cmd->args[i++]);
	printf("\n				\n");
	printf("\n				DATA INSIDE THE STRUCTURE:\n");
	printf("				Clean words		: %d\n", cmd->words);
	printf("				Quotes	   		: %d\n", cmd->quotes);
	printf("				Double quotes		: %d\n", cmd->double_quotes);
	printf("				Pipes			: %d\n", cmd->pipes);
	printf("				Output Redirect		: %d\n", cmd->greater);
	printf("				Input Redirect		: %d\n", cmd->lesser);
	printf("				Dollars			: %d\n", cmd->dollars);
	printf("				Double Redirections		: %d\n", cmd->double_redir);
}

void ft_chopeadito(t_cmd *args, t_env *env, char *prompt)
{
	char *aux;

	aux = prompt;
	init_args(args);
	add_history(aux);
	get_data(args, aux);
	get_token(args, aux);
	//print(args);
	get_inter(args, env);
	ft_selector(args, env);
	free_args(args);
}

void my_signal(int sig)
{
	if (sig == 2)
	{
		write(1, "Shootgun=▸  ", 15);
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int main(int argc, char **argv, char **envp)
{
	t_env env;
	t_cmd args;
	char *prompt;

	env.env = ft_env_strdup(envp);
	env.oldpwd = NULL;
	init_args(&args);
	signal(SIGINT, my_signal);
	signal(SIGQUIT, SIG_IGN);
	while (1 && argc && argv)
	{
		prompt = readline("Shootgun=▸");
		if (!prompt)
			break;
		if (!prompt[0])
			continue;
		ft_chopeadito(&args, &env, prompt);
	}
	ft_doublefree(env.env);
	free(env.oldpwd);
	return (0);
}
