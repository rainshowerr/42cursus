/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:37:51 by marvin            #+#    #+#             */
/*   Updated: 2022/07/08 18:37:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlen(const char	*src)
{
	size_t	k;

	k = 0;
	while (src[k] != '\0')
		k++;
	return (k);
}

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *str;
    int i;
    
    if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
        return (0);
    i = 0;
    while(i < (int)ft_strlen(s))
    {
        str[i] = f(i, s[i]);
        i++;
    }
    return (str);
}