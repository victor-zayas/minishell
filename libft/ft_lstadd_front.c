/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:30:47 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/05/09 16:27:52 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!lst)
	{
		*lst = new;
		return ;
	}
	new ->next = *lst;
	*lst = new;
}

/* int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*start;

	start = ft_lstnew("Bitcoin ");
	node1 = ft_lstnew("es ");
	node2 = ft_lstnew("libertad ");
	node3 = ft_lstnew("!");
	start->next = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	ft_lstadd_front(&node1, start);
	while (node1)
	{
		printf("%s", node1->content);
			node1 = node1->next;
	}
} */