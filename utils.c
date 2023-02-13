/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:10:06 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/13 16:38:19 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void print_num(long num)
{
    char    c;

    if (num < 0)
    {
        write(1, "-", 1);
        c = '0' + num % 10;
        print_num(-(num / 10));
    }
    else
    {
        c = '0' + num % 10;
        if (num / 10 != 0)
            print_num(num / 10);
    }
    write(1, &c, 1);
}

size_t ft_strlen(char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void print_msg(char *msg)
{
    write(1, msg, ft_strlen(msg));
}
