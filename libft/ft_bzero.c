/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 17:56:24 by marvin            #+#    #+#             */
/*   Updated: 2022/07/10 17:56:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <includes/libft.h>

void ft_bzero(void *s, size_t n)
{
    size_t i;
    unsigned char *ss;
    
    ss = (unsigned char *)s;
    i = 0;
    while(i < n)
    {
        ss[i] = 0;
        i++;
    }
}
