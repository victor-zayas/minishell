/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:44:17 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/11 11:30:23 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief This function needs two arguments to work, (<<) && (delimiter),
 * 	Basically, it is responsible of reading the users input once the command
 * 	is executed, until the delimiter that you have given is found in the input.
 * 	// Introduction
 * 	Once the delimiter is found, heredoc just stops reading the input and
 * 	DOES NOT PRINT NOTHING ON SCREEN, NOTHING BUT A NEWLINE.
 * 
 * 	Of course, if you give it a command like [cat], before the heredoc, it will
 * 	print the read values until the last one (not included).
 * 	// Input-> open/fd/unlink
 * 	Every programmer should know that if we have an input, we have something
 * 	that we can read, so in this case, since we want to keep the input (do not
 * 	ask me why, heredoc just works like that) we need something to keep it.
 * 
 * 	In our program, we have used a file to store the input, I have given it the
 * 	name: "heredoc_tmp".
 * 	Basically, all the input recieved that does not match the delimiter, is
 * 	directly stored in there separated with a newline.
 * 
 * 	Once we have readen the delimited, we use the new "unlink" function,
 * 	that closes "heredoc_tmp" and leaves no race of our actions.
 * 	// Loop
 * 	How do we know if the given argument is the demiliter?
 * 	Easy, we just use "readline" function along with a never-ending loop,
 * 	the returning value of readline is the string we need to compare with
 * 	the delimiter.
 * 
 * 	We do that with ft_strlen and ft_strncmp, if the input is concordant
 * 	with the delimiter, we break the loop.
 * 
 * 	Else,
 * 	We just write the string ONTO THE OPENED FILE!! NOT STDOUT!!
 * @param arg 
 */

void	ft_get_heredoc(char	*arg)
{
	int		fd;
	char	*input;

	fd = open("heredoc_tmp", O_CREAT | O_RDWR | O_TRUNC, 0600);
	while (1)
	{
		input = readline("heredoc> ");
		if (ft_strlen(input) == ft_strlen(arg)
			&& !ft_strncmp(input, arg, ft_strlen(input)))
			break ;
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 2);
		free (input);
	}
	close(fd);
	free(input);
}

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

int	ft_dinput(t_cmd	*cmd, int i)
{
	pid_t	pid;
	int		fd;
	int		flag;

	flag = 0;
	pid = fork();
	if (pid == 0)
	{
		signal(SIGINT, my_signal_exit);
		ft_get_heredoc(cmd->args[i]);
		exit (0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		waitpid(pid, &flag, 0);
		fd = open("heredoc_tmp", O_RDONLY);
		dup2(fd, STDIN_FILENO);
		close(fd);
		unlink("heredoc_tmp");
		if (WEXITSTATUS(flag) == 130)
			return (2);
	}
	return (EXIT_SUCCESS);
}
