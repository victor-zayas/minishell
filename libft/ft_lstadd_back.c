/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:54:35 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/05/09 15:21:15 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	aux = ft_lstlast(*lst);
	aux->next = new;
}

/* int	main(void)
{
	t_list	*p;
	t_list	*p1;
	t_list	*p2;
	t_list	*nbc;
	nbc = ft_lstnew("(LAST)");
	p = ft_lstnew("1 ");
	p1 = ft_lstnew("2 ");
	p2 = ft_lstnew("3 ");
	p->next = p1;
	p1->next = p2;
	p2->next = NULL;
	ft_lstadd_back(&p, nbc);
	while (p)
	{
		printf("%s", p->content);
		p = p->next;
	}
} */
