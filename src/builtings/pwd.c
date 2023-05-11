/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:50:36 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/05/11 06:49:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_pwd(t_cmd	*cmd, int open)
{
	char	*pwd;
	int		flag;
	pid_t	pid;

	if (open)
	{
		pid = fork();
		if (pid == 0)
		{
			if (open_fd(cmd))
				exit (1);
			exit(ft_pwd(cmd, 0));
		}
		waitpid(pid, &flag, 0);
		return (WEXITSTATUS(flag));
	}
	pwd = getcwd(NULL, 0);
	if (pwd == NULL)
	{
		printf("%s\n", strerror(errno));
		return (1);
	}
	printf("%s\n", pwd);
	free(pwd);
	return (0);
}
