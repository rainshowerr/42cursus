/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:18:35 by seoshin           #+#    #+#             */
/*   Updated: 2023/01/19 19:59:35 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

static void	ft_putn(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		ft_putnbr(n);
	}
	else if (n <= 9)
	{
		ft_putn(n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putn(n % 10);
	}
}

void	ft_putnbr_n_newline(int n)
{
	ft_putnbr(n);
	write(1, "\n", 1);
}

int	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return (1);
	while (haystack[i])
	{
		while (haystack[i + j] && haystack[i + j] == needle[j] && i + j < len)
			j++;
		if (!needle[j] && !haystack[i + j])
			return (1);
		i++;
		j = 0;
	}
	return (0);
}