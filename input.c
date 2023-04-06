/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:44:17 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/06 13:50:19 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_input(t_cmd *cmd, int i)
{
	int	fd;

	fd = open(cmd->args[i], O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	while (cmd->args[i + 1] && !ft_strncmp(cmd->args[i + 1], "<", 1))
	{
		i++;
		if (cmd->args[i + 1])
			i++;
		else
		{
			write(2, "bash: syntax error near unexpected token `newline'\n", 52);
			return (0);
		}
		fd = open(cmd->args[i], O_RDONLY);
		if (fd < 0)
			return (EXIT_FAILURE);
	}
	dup2(fd, STDIN_FILENO);
	return (EXIT_SUCCESS);
}

int	ft_dinput(__attribute__((unused)) t_cmd	*cmd, __attribute__((unused)) int i)
{
	char 	str[1024];

	while(read(STDIN_FILENO, &str, 1024) > 0)
	{
		// If string readen is equal to argument that follows '<<' return
		if (!ft_strncmp(str, cmd->args[i - 1], ft_strlen(str)))
			return (EXIT_SUCCESS);
		printf("string entered -> [%s]", str);
		printf("string to compare -> [%s]", cmd->args[i - 1]);
		// Else, keep reading
	}
	return (EXIT_SUCCESS);
}
