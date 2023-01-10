/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:11:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/10/26 12:21:17 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char	*error)
{
	size_t	len;

	len = ft_strlen(error);
	write(1, error, len);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_error(int d1, char	*infile)
{
	close(d1);
	write(1, "zsh: no such file or directory: ", 32);
	while (*infile)
	{
		write (1, &*infile, 1);
		infile++;
	}
	write (1, "\n", 1);
}

void	pipex(int f_1, int f_2, char	**args, char	**env)
{
	pid_t	pid;
	int		fd[2];
	int		check;

	check = 0;
	if (pipe(fd) == -1)
		error ("pipe");
	pid = fork();
	if (pid < 0)
		error("fork");
	if (pid == 0)
	{
		ft_child (f_1, args[2], env, fd);
	}
	waitpid (pid, NULL, 0);
	ft_adult (f_2, args[3], env, fd);
}

int	main(int argc, char	**argv, char	**envp)
{
	int	f1;
	int	f2;

	if (argc != 5)
		error("Expected: ./pipex infile command1 | command2 outfile");
	f1 = open (argv[1], O_RDONLY);
	if (f1 < 0)
	{
		ft_error (f1, argv[1]);
		exit(EXIT_FAILURE);
	}
	f2 = open (argv[4], O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (f2 < 0)
	{
		ft_error (f2, argv[4]);
		exit(EXIT_FAILURE);
	}
	pipex (f1, f2, argv, envp);
	return (0);
}
