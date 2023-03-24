/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:56:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/03/23 21:41:36 by jaizpuru         ###   ########.fr       */
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
	//cmd->env->exit_value = 1;
	if (cmd->atrb)
		exit (1);
}

void	input_handle(t_cmd	*cmd, int i)
{
	if (cmd->in + cmd->double_in == 0)
		return ;
	if (i == cmd->input[cmd->in_it])
	{
		if (!ft_strncmp(cmd->args[i - 1], "<<", 3))
			cmd->flag = ft_dinput(cmd, i);
		else
			cmd->flag = ft_input(cmd, i);
		if (cmd->flag == 1)
			ft_descriptor_error(cmd, i);
		cmd->in_it++;
	}
}

void	output_handle(t_cmd	*cmd, int i)
{
	if (cmd->out + cmd->double_out == 0)
		return ;
	if (i == cmd->output[cmd->out_it])
	{
		if (!ft_strncmp(cmd->args[i - 1], ">>", 3))
			cmd->flag = ft_doutput(cmd, i);
		else
			cmd->flag = ft_output(cmd, i);
		if (cmd->flag == 1)
			ft_descriptor_error(cmd, i);
		cmd->out_it++;
	}
}

void	open_fd(t_cmd *cmd)
{
	int	i;

	i = 0;
	cmd->flag = 0;
	cmd->in_it = 0;
	cmd->out_it = 0;
	while (cmd->args[i] && (cmd->in >= 1 || cmd->out >= 1
			|| cmd->double_in >= 1 || cmd->double_out >= 1))
	{
		input_handle(cmd, i);
		output_handle(cmd, i);
		i++;
	}
}
