/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:07:51 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/05/09 16:51:46 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*res;

	if (!lst)
		return (0);
	new = 0;
	while (lst)
	{
		res = ft_lstnew(f(lst->content));
		if (!(res))
		{
			ft_lstclear(&new, del);
			return (0);
		}
		ft_lstadd_back(&new, res);
		lst = lst->next;
	}
	return (new);
}
