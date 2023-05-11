/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:24:42 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/05/11 13:26:40 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief This function check if there is redir in "echo" builting.
 * 
 * @param args 
 * @param cmd Command with option.
 * @param open Int for open the file descriptor
 * @return int 
 */
int	check_open(t_cmd *args, char **cmd, int open)
{
	pid_t	pid;
	int		flag;

	if (open)
	{
		pid = fork();
		if (pid == 0)
		{
			if (open_fd(args))
				exit (1);
			exit(ft_echo(args, cmd, 0));
		}
		waitpid(pid, &flag, 0);
		return (WEXITSTATUS(flag));
	}
	return (0);
}

void	ft_dash_echo(char	**cmd, int i)
{
	while (cmd[i])
	{
		if (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
			i++;
		else if ((i > 2))
			printf(" %s", cmd[i++]);
		else
			printf("%s", cmd[i++]);
	}
}

void	ft_echo_trim(char	**cmd)
{
	int		len;
	char	*str;

	len = 0;
	str = NULL;
	while (cmd[len])
	{
		str = ft_strdup(cmd[len]);
		if (ft_strchr(cmd[len], '\"') || ft_strchr(cmd[len], '\''))
			free(cmd[len]);
		if (ft_strchr(str, '\"'))
			cmd[len] = ft_strtrim(str, "\"");
		else if (ft_strchr(str, '\''))
			cmd[len] = ft_strtrim(str, "\'");
		free(str);
		len++;
	}
}

int	ft_echo(t_cmd *args, char **cmd, int open)
{
	int		i;

	i = 1;
	if (open)
		return (check_open(args, cmd, open));
	ft_echo_trim(cmd);
	if (cmd[i] && !ft_strncmp(cmd[i], "-n", 2))
	{
		ft_dash_echo(cmd, ++i);
		return (0);
	}
	while (cmd[i])
	{
		if ((i > 1))
			printf(" %s", cmd[i++]);
		else
			printf("%s", cmd[i++]);
	}
	printf("\n");
	return (0);
}
