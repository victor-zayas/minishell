/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:50:49 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/04/23 20:30:34 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_descriptor_error(t_cmd	*cmd, int i)
{
	write(2, "bash: ", 7);
	write(2, cmd->args[i], ft_strlen(cmd->args[i]));
	write(2, ": No such file or directory\n", 29);
	i = 0;
	while (cmd->args[i])
		free(cmd->args[i++]);
	free(cmd->args);
	if (cmd->in || cmd->double_in)
		free(cmd->input);
	if (cmd->out || cmd->double_out)
		free(cmd->output);
	if (cmd->atrb)
		exit (1);
}

void	pipe_error(t_cmd	*cmd, t_env	*env)
{
	write(2, "bash: syntax error near unexpected token ", 42);
	write(2, *cmd->args, 1);
	write(2, "\n", 2);
	env->exit_value = 1;
	return ;
}

void	error(char *error)
{
	size_t	len;

	len = ft_strlen(error);
	write(1, error, len);
	write(1, "\n", 1);
	exit(EXIT_FAILURE);
}

int	error_code(char *cmd, t_env	*env)
{
	return (is_directory(cmd, env));
}

int	is_directory(char *path, t_env *env)
{
	struct stat	statbuf;

	write(2, "bash: ", 7);
	write(2, path, ft_strlen(path));
	if (stat(path, &statbuf) != 0)
	{
		write(2, ": command not found\n", 21);
		env->exit_value = 127;
		return (127);
	}
	write(2, ": Is a directory\n", 18);
	env->exit_value = 126;
	return (126);
}
