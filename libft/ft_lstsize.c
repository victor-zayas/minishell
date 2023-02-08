/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:30:13 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/05/09 16:51:33 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list	*lst)
{
	int	num;

	if (!lst)
		return (0);
	num = 0;
	while (lst)
	{
		lst = lst->next;
		num++;
	}
	return (num);
}
