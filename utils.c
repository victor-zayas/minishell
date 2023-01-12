/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:00:16 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/01/12 15:34:24 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	init_args(t_cmd	*new)
{
	new->args = NULL;
	new->size = 0;
	new->quotes = 0;
}

void	get_token(t_cmd	*cmd, char	*line)
{
	int	i;
	int	start;
	int	j;

	i = -1;
	j = 0;
	start = 0;
	cmd->args = (char	**)malloc(sizeof(char	*) * (cmd->quotes + cmd->double_quotes + cmd->pipes + 1)); // IMPORTANT!
	while(line[++i])
	{
		if((line[i] == '\'') && line[i])
		{
			line = quotes_lexer(cmd, line, i);
			i = 0;
		}
		if (line[i] == '"' && line[i])
		{
			line = double_quotes_lexer(cmd, line, i);
			i = 0;
		}
		if (line[i++] == '|' && line[i]) 
		{
			line = pipes_lexer(cmd, line, i);
			i = 0;
		}
	}
	cmd->args[j] = NULL;
	i = 0;
	while((cmd->args)[i])
	{
		printf("I got this: %s\n", cmd->args[i]);
		i++;
	}
}

char	*ft_path(char	**enviroment_path)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	while (enviroment_path[i])
	{
		res = ft_strnstr(enviroment_path[i], "PATH=", 5);
		if (res)
		{
			res = ft_substr(enviroment_path[i], 5, ft_strlen(res));
			break ;
		}
		i++;
	}
	return (res);
}

char	*get_cmd(char	*arguments, char	**enviroment)
{
	char	**path;
	char	*env;
	char	*sup;
	char	*sup2;
	int		i;

	i = 0;
	env = ft_path(enviroment);
	path = ft_split(env, ':');
	free(env);
	while (path[i])
	{
		sup = ft_strjoin(path[i], "/");
		sup2 = ft_strjoin(sup, arguments);
		free(sup);
		if (access(sup2, 0) == 0)
			return (sup2);
		free (sup2);
		i++;
	}
	i = -1;
	while (path[++i])
		free (path[i]);
	free (path);
	return (0);
}