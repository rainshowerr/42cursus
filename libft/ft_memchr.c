/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:08:13 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/07 18:17:48 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	to_find;
	size_t			i;

	str = (unsigned char *)s;
	to_find = (unsigned char)c;
	i = 0;
	while(i < n)
	{
		if (str[i] == to_find)
			return (void *)&str[i];
		i++;
	}
	return 0;
}

/*
#include <stdio.h>
#include <string.h>

int main() {
	char* pch;
	char str[] = "Example string";
	pch = (char*)ft_memchr(str, 'E', strlen(str));

	if (pch != NULL)
    	printf("'p' found at position %ld.\n", pch - str + 1);
	else
    	printf("'p' not found.\n");
		
  return 0;
}
*/