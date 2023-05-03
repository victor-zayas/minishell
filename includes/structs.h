/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 08:56:41 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/03 08:58:25 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_it
{
	int	i1;
	int	i2;
	int	i3;
	int	i4;
	int	i5;
	int	i6;
	int	i7;
}	t_it;

typedef struct s_env
{
	char	*oldpwd;
	char	*pwd;
	char	**env;
	char	**aux;
	int		exit_value;
}	t_env;

typedef struct s_cmd
{
	t_it	i;
	t_env	*env;
	char	**args;
	char	**cmd;
	char	**atrb;

	int		n_cmd;
	int		size;
	int		flag;

	int		words;
	int		quotes;
	int		dollars;
	int		pipes;
	int		double_quotes;
	int		out;
	int		in;
	int		double_in;
	int		double_out;

	int		*input;
	int		in_it;
	int		*output;
	int		out_it;

	int		cmd_start;
	int		pipe_pos;
	int		block_pos;
	int		redir_end;
}	t_cmd;

#endif