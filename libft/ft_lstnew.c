/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaizpuru <jaizpuru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:51:20 by jaizpuru          #+#    #+#             */
/*   Updated: 2022/05/09 11:27:15 by jaizpuru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!(new))
		return (0);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	char	*str = "Buenas Tardes";
	t_list	*estructura;

	estructura = ft_lstnew(str);
	printf("%s\n", estructura->content);
} */
