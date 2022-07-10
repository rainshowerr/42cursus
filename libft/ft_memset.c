/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:50:25 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/07 16:47:40 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char * bb;
	size_t			i;
	
	bb = (unsigned char *)b;
	c = (unsigned char)c;
	i = 0;
	while(i < len)
	{
		bb[i] = c;
		i++;
	}
	return (void *)bb;
}
