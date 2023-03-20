/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:46 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/20 18:52:22 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	shell_level(t_cmd	*cmd, t_env	*env)
{
	int		i;
	char	*aux;

	i = 0;
	while(cmd->args[i])
	{
		if (!ft_strncmp(cmd->args[i], "./minishell", 11))
		{
			(env->shell_lvl)++;
			aux = ft_strjoin("SHLVL=", ft_itoa((env->shell_lvl)));
			ft_export(env, aux, "export");
			free(aux);
			return ;
		}
		i++;
	}
}

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
	args->input = (int *)malloc(sizeof(int *) * args->greater);
	args->output = (int *)malloc(sizeof(int *) * args->lesser);
	get_token(args, aux);
	get_inter(args, env);
	//print(args);
	shell_level(args, env);
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
