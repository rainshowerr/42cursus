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

#include <stdlib.h>

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

/*
#include <stdio.h>
int main(void)
{
	int A[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ft_memmove(A + 1, A, 9 * sizeof(int));
	printf("%d %d %d %d", A[0], A[1], A[2], A[3]);
}
*/