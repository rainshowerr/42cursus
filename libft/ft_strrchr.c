/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:43:03 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:43:03 by seoshin          ###   ########.fr       */
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

char	*ft_strrchr(const char *s, int c)
{
	size_t		idx;

	idx = ft_strlen(s);
	while (0 <= (int)idx)
	{
		if (s[idx] == c)
			return ((char *)&s[idx]);
		idx--;
	}
	return (0);
}
