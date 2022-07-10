/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:42:39 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:42:39 by seoshin          ###   ########.fr       */
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

char	*strchr(const char *s, int c)
{
	int idx;

	idx = 0;
	while (idx <= (int)ft_strlen(s))
	{
		if (s[idx] == c)
			return ((char *)&s[idx]);
		idx++;
	}
	return 0;
}