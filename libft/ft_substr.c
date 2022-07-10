/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:45:33 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:45:33 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *str;
    size_t  i;

    str = (char *)malloc(sizeof(char) * (len + 1));
    i = 0;
    while(i < len)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    return str;
}
