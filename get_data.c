/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:33:36 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/17 18:37:59 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_data(t_cmd	*args, char	*prompt)
{
	args->words = get_words(prompt);
	args->quotes = get_quotes(prompt);
	if(args->quotes % 2 != 0)
	{
		printf("Error\n");
		exit (EXIT_FAILURE);
	}
	args->double_quotes = get_double_quotes(prompt);
	if(args->double_quotes % 2 != 0)
	{
		printf("Error\n");
		exit (EXIT_FAILURE);
	}
	args->pipes = get_pipes(prompt);
	args->lesser = get_lesser(prompt);
	args->greater = get_greater(prompt);
	args->quotes /= 2;
	args->double_quotes /= 2;
}

int	get_words(char	*prompt)
{
	int	i;
	int	checker;
	int	sp;

	sp = 0;
	i = 0;
	checker = 0;
	while(prompt[i] == ' ' && prompt[i] >= '0' && prompt[i] <= '9' && prompt[i] != '\t')
		i++;
	while(prompt[i])
	{
		if((prompt[i] == '\'' || prompt[i] == '"' || prompt[i] == '|') && prompt[i + 1])
		{
			sp += 1;
			i++;
		}
		if(prompt[i] >= 'a' && prompt[i] <= 'z' && (sp % 2) == 0)
		{
			checker++;
			while (prompt[i] >= 'a' && prompt[i] <= 'z' && (sp % 2) == 0)
				i++;
		}
		i++;
	}
	return (checker);
}

int	get_quotes(char	*prompt)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == ('\''))
			checker++;
		i++;
	}
	return (checker);
}

int	get_double_quotes(char	*prompt)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == ('"'))
			checker++;
		i++;
	}
	return (checker);
}

int	get_pipes(char	*prompt)
{
	int	i;
	int	checker;

	checker = 0;
	i = 0;
	while (prompt[i])
	{
		if (prompt[i] == ('|'))
			checker++;
		i++;
	}
	return (checker);
}
