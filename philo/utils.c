/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:38:40 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/13 21:24:34 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long long	get_time(void)
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec * 1000);
}

static int	ft_check(unsigned long long k, int sign)
{
	unsigned long long	max;

	max = 9223372036854775807;
	if (k > max && sign > 0)
		return (-1);
	else if (k > max && sign < 0)
		return (0);
	else
		return (sign * (int)k);
}

int	ft_atoi(const char *str)
{
	int					idx;
	int					sign;
	unsigned long long	k;

	idx = 0;
	sign = 1;
	k = 0;
	while (('\t' <= str[idx] && str[idx] <= '\r') || str[idx] == ' ')
		idx++;
	if (str[idx] == '-' || str[idx] == '+')
	{
		if (str[idx] == '-')
			sign = -1;
		idx++;
	}
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		k += str[idx] - '0';
		if ('0' <= str[idx + 1] && str[idx + 1] <= '9')
			k *= 10;
		idx++;
	}
	return (ft_check(k, sign));
}