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

#include "./libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;
	size_t			i;

	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	if (to == 0 && from == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		to[i] = from[i];
		i++;
	}
	return ((void *)to);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*to;
	unsigned char	*from;
	int				i;

	to = (unsigned char *) dst;
	from = (unsigned char *) src;
	if (to == 0 && from == 0)
		return (0);
	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		i = (int)(len - 1);
		while (0 <= i)
		{
			to[i] = from[i];
			i--;
		}
	}
	return ((void *)to);
}
