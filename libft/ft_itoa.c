/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:44:18 by seoshin           #+#    #+#             */
/*   Updated: 2022/07/10 20:44:18 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static size_t	ft_space(int n)
{
	size_t	space;

	if (n == 0)
		return (1);
	space = 0;
	if (n < 0)
		space++;
	while (n)
	{
		n /= 10;
		space++;
	}
	return (space);
}

char	*ft_itoa(int n)
{
	char		*ans;
	int			idx;
	long long	nn;

	nn = (long long)n;
	ans = (char *)malloc(sizeof(char) * (ft_space(nn) + 1));
	if (!ans)
		return (0);
	idx = ft_space(nn);
	ans[idx--] = '\0';
	if (nn == 0)
		ans[idx] = '0';
	else if (nn < 0)
	{
		ans[0] = '-';
		nn *= -1;
	}
	while (nn)
	{
		ans[idx--] = (nn % 10) + '0';
		nn /= 10;
	}
	return (ans);
}
