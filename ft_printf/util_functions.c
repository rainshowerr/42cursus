/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 21:47:10 by seoshin           #+#    #+#             */
/*   Updated: 2022/08/07 22:11:01 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char	*src)
{
	size_t	k;

	k = 0;
	while (src[k] != '\0')
		k++;
	return (k);
}

static int	ft_putn(int n)
{
	char	c;

	c = n + '0';
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		len += ft_putnbr(n) + 1;
	}
	else if (n <= 9)
	{
		len += ft_putn(n);
	}
	else
	{
		len += ft_putnbr(n / 10);
		len += ft_putn(n % 10);
	}
	return (len);
}

int	ft_hexadec(unsigned long long nbr, char *base)
{
	int		len;

	len = 0;
	if (nbr < 16)
		write(1, &base[nbr], 1);
	else
	{
		len += ft_hexadec(nbr / 16, base);
		write(1, &base[nbr % 16], 1);
	}
	len++;
	return (len);
}
