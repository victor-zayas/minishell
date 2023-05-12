/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prompt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:17:08 by jaizpuru          #+#    #+#             */
/*   Updated: 2023/05/11 08:38:16 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief	Checks whether there is any special character involving 
 * 			the Bonus Part inside the Prompt given by the user
 * 
 * 			In case, there is, the enviroment structure and its corresponding
 * 			values are freed and an error message is returned to the user.
 * 
 * @param env 
 * @param prompt 
 * @return int 
 */

int	ft_check_prompt(char *prompt)
{
	if (ft_chr_in_set(';', prompt) || !ft_strncmp(prompt, "||", 2)
		|| !ft_strncmp(prompt, "&&", 2) || ft_chr_in_set('*', prompt))
		return (free(prompt),
			ft_putstr_fd("syntax error: special character\n", 2), 1);
	else
		return (0);
}
