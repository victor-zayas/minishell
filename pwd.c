/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:50:36 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/03/24 12:01:46 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(t_cmd	*cmd, int open)
{
	char	*pwd;
	pid_t	pid;

	if (open)
	{
		pid = fork();
		if (pid == 0)
		{
			open_fd(cmd);
			ft_pwd(cmd, 0);
			exit (0);
		}
		waitpid(pid, NULL, 0);
		return (0);
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		printf("%s\n", strerror(errno));
		return (0);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
