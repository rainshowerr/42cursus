/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:18:50 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/07 18:52:52 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while(!(str1[i] == '\0' && str2[i] == '\0') && i < n)
	{
		if (str1[i] != str2[i])
			return str1[i] - str2[i];
		i++;
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
int main()
{
	const char *s1 = "abc";
	const char *s2 = "abe";
	printf("%d\n", ft_memcmp(s1, s2, 10));
	printf("%d", memcmp(s1, s2, 10));
}