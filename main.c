/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:46 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/01/10 20:14:47 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	ft_chopeadito(char	*prompt, char	**env)
{
	char		**args;
	char		*path;
	char		*aux;

	aux = prompt;
	args = ft_split(aux, ' ');
	path = get_cmd(*args, env);
	execve(path, args, env);
	add_history(aux);
	free(prompt);
}

int	main(int argc, char **argv, char	**env)
{
	char	*prompt;

	while (1 && argc && argv)
	{
		prompt = readline("Shootgun =>");
		if (prompt)
			ft_chopeadito(prompt, env);
	}
	return (0);
}
