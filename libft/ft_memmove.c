/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:44:27 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:44:27 by seoshin          ###   ########.fr       */
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
	while (i < len)
	{
		temp[i] = from[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		to[i] = temp[i];
		i++;
	}
	return ((void *)to);
}
