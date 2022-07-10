/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:41:20 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:41:20 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*space;
	size_t	i;

	space = (void *)malloc(nmemb * size);
	if (!space)
		return (0);
	i = 0;
	while (i < size)
		space[i] = 0;
	return (space);
}
