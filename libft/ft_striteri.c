/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:45:08 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:45:08 by seoshin          ###   ########.fr       */
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

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(s))
	{
		f(i, &s[i]);
		i++;
	}
}
