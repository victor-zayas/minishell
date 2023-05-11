/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:04:01 by vzayas-s          #+#    #+#             */
/*   Updated: 2023/05/11 07:36:12 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"

/**
 * @brief Used to know how many blocks were allocated and what values
 * 	does each token get whenever we inset some input to the prompt.
 * 
 * @param cmd 
 */

void	print(t_cmd *cmd)
{
	int	i;

	i = 0;
	printf("\n				ARGS INSIDE THE STRUCTURE:\n");
	printf("				ARGS -> ");
	while (cmd->args[i])
		printf("[%s] ", cmd->args[i++]);
	printf("\n				\n");
	printf("\n				DATA INSIDE THE STRUCTURE:\n");
	printf("				Clean words		: %d\n", cmd->words);
	printf("				Quotes	   		: %d\n", cmd->quotes);
	printf("				Double quotes		: %d\n", cmd->double_quotes);
	printf("				Pipes			: %d\n", cmd->pipes);
	printf("				Output Redirect		: %d\n", cmd->out);
	printf("				Input Redirect		: %d\n", cmd->in);
	printf("				Dollars			: %d\n", cmd->dollars);
	printf("				Double Input Redirection	: %d\n", cmd->double_in);
	printf("				Double Output Redirect	: %d\n", cmd->double_out);
}
