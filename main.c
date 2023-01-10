/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:11:46 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/01/10 19:28:13 by vzaya-s          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	ft_chopeadito(char	*prompt)
{
	char	*aux;

	aux = ft_strtrim(prompt, " ");
	free(prompt);
	add_history(aux);
}

int	main(int argc, char **argv)
{
	char	*prompt;

	while (1 && argc && argv)
		prompt = readline("Shootgun =>");
	return (0);
}
