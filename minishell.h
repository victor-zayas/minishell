#ifndef MINISHELL_H
# define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "libft/pipex/pipex.h"

char	*get_cmd(char	*arguments, char	**enviroment);
void	ft_chopeadito(char	*prompt, char	**env);

#endif