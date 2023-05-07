/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:27:27 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/07 11:05:13 by jaizpuru         ###   ########.fr       */
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

int	find_sp(char **args, int i)
{
	int	len;

	len = 0;
	while (args[i])
	{
		if (!ft_strncmp(args[i], "|", 2) || !ft_strncmp(args[i], "||", 3))
			break ;
		else if (!ft_strncmp(args[i], ">", 2) || !ft_strncmp(args[i], "<", 2)
			|| !ft_strncmp(args[i], "<<", 3) || !ft_strncmp(args[i], ">>", 3))
		{
			if (args[i + 1])
				i++;
			else
				return (0);
			len += 2;
		}
		i++;
	}
	if (args[i] && !ft_strncmp(args[i], "|", 2) && ((!args[i + 1])
			|| !ft_strncmp(args[i + 1], "|", 2)))
		return (-1);
	return (i - len);
}
