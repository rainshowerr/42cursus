/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:56:27 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/07 18:05:20 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*to;
	unsigned char	*from;
	unsigned char	temp[len];
	size_t			i;

	to = (unsigned char *) dst;
	from = (unsigned char *) src;
	i = 0;
	while(i < len)
	{
		temp[i] = from[i];
		i++;
	}
	i = 0;
	while(i < len)
	{
		to[i] = temp[i];
		i++;
	}
	return (void *)to;
}
