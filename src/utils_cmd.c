/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:27:27 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/04/23 20:58:35 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

void	close_str(char	**ar, int end, int sp)
{
	if (sp)
		ar[sp] = NULL;
	else
		ar[end] = NULL;
}

int	get_last_redir(char	**str, int pos)
{
	int	flag;

	flag = 0;
	while (str[pos])
	{
		pos = find_pipe(str, pos);
		if (str[pos] && str[pos + 1])
			pos++;
	}
	while (str[pos - 1] && ft_strncmp(str[pos - 1], "|", 1))
	{
		pos--;
		if (!ft_strncmp(str[pos], ">", 1)
			|| !ft_strncmp(str[pos], "<", 1))
			flag = 1;
	}
	if (flag)
		return (pos);
	return (0);
}
