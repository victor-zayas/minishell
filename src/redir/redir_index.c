/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 00:56:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/11 14:05:58 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	input_handle(t_cmd	*cmd, int i)
{
	if (cmd->in + cmd->double_in == 0)
		return (0);
	if (i == cmd->input[cmd->in_it])
	{
		if (cmd->args[i] && (!ft_strncmp(cmd->args[i], ">>", 3)
				|| !ft_strncmp(cmd->args[i], "<<", 3)))
			return (write(2,
					"bash: syntax error near unexpected token `newline'\n",
					52), 1);
		if (!ft_strncmp(cmd->args[i - 1], "<<", 3))
			cmd->flag = ft_dinput(cmd, i);
		else
			cmd->flag = ft_input(cmd, i);
		if (cmd->flag == 1)
		{
			ft_descriptor_error(cmd, i);
			return (1);
		}
		if (cmd->flag == 1)
			return (1);
		cmd->in_it++;
	}
	return (0);
}

int	output_handle(t_cmd	*cmd, int i)
{
	if (cmd->out + cmd->double_out == 0)
		return (0);
	if (i == cmd->output[cmd->out_it])
	{
		if (cmd->args[i] && (!ft_strncmp(cmd->args[i], ">>", 3)
				|| !ft_strncmp(cmd->args[i], "<<", 3)))
			return (write(2,
					"bash: syntax error near unexpected token `newline'\n",
					52), 1);
		if (!ft_strncmp(cmd->args[i - 1], ">>", 3))
			cmd->flag = ft_doutput(cmd, i);
		else
			cmd->flag = ft_output(cmd, i);
		if (cmd->flag == 1)
		{
			ft_descriptor_error(cmd, i);
			return (1);
		}
		if (cmd->flag == 2)
			return (2);
		cmd->out_it++;
	}
	return (0);
}

int	open_fd(t_cmd *cmd)
{
	int	i;
	int	input_flag;
	int	output_flag;

	i = 0;
	input_flag = 0;
	output_flag = 0;
	cmd->flag = 0;
	cmd->in_it = 0;
	cmd->out_it = 0;
	while (cmd->args[i] && (cmd->in >= 1 || cmd->out >= 1
			|| cmd->double_in >= 1 || cmd->double_out >= 1))
	{
		input_flag = input_handle(cmd, i);
		if (input_flag == 1)
			return (1);
		output_flag = output_handle(cmd, i);
		if (output_flag == 1)
			return (1);
		i++;
	}
	return (0);
}
