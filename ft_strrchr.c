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

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		idx;
	char	cc;

	cc = (char)c;
	idx = (int)ft_strlen(s);
	while (0 <= idx)
	{
		if (s[idx] == cc)
			return ((char *)&s[idx]);
		idx--;
	}
	return (0);
}
