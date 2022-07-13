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

#include "./libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		idx;
	char	cc;

	cc = (char)c;
	idx = 0;
	while (idx <= (int)ft_strlen(s))
	{
		if (s[idx] == cc)
			return ((char *)&s[idx]);
		idx++;
	}
	return (0);
}
