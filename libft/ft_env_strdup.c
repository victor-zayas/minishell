/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzaya-s <vzaya-s@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:24:50 by vzaya-s           #+#    #+#             */
/*   Updated: 2023/01/30 19:08:47 by vzaya-s          ###   ########.fr       */
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
        if (ft_strncmp(str[i], "OLDPWD=", 7) == 0)
        {
            aux = (char **)malloc(sizeof(char *) * (ft_bid_strlen(str)));   
            if (!aux)
                return (NULL);
            i = -1;
            while (str[++i])
            {
                if (ft_strncmp(str[i], "OLDPWD=", 7) != 0)
                    aux[i] = ft_strdup(str[i]);
            }
            aux[i - 1] = '\0';
            return (aux);
        }
    }
    if (!aux)
    {
        aux = (char **)malloc(sizeof(char *) * (ft_bid_strlen(str) + 1));
        if (!aux)
            return (NULL);
        i = -1;
        while (str[++i])
            aux[i] = ft_strdup(str[i]);
        aux[i] = '\0';   
    }
    return (aux);
}
