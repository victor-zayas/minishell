/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzayas-s <vzayas-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:50 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/02/08 17:27:13 by vzayas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    **ft_env_strdup(char **str)
{
    char    **aux;
    int        i;

    i = -1;
    aux = NULL;
    while (str[++i])
    {
        aux = (char **)malloc(sizeof(char *) * (ft_bid_strlen(str)) + 1);
        if (!aux)
            return (NULL);
        i = -1;
        while (str[++i])
        {
            if (!ft_strncmp(str[i], "OLDPWD=", 7) && str[i])
                break ;
            aux[i] = ft_strdup(str[i]);
        }
        aux[i] = '\0';
        return (aux);
    }
    return (aux);
}
