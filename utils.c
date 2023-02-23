/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:08:58 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/23 23:50:08 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void	node_clear(t_deque *deque)
{
	t_node	*node;
	t_node	*temp;

	node = deque->top;
	while(node)
	{
		temp = node;
		node = node->next;
		free(temp);
	}
}

void	print_emsg(t_deque *deque)
{
	write(1, "Error\n", 6);
	node_clear(deque);
	exit(1);
}

static int	ft_check(unsigned long long k, int sign, t_deque *deque)
{
	unsigned long long	max;
	long long			num;

	if ((sign > 0 && k > 2147483647) || (sign < 0 && k > 2147483648))
			print_emsg(deque);
	return (sign * (int)k);
}

int	ft_atoi(const char *str, t_deque *deque)
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
	return (ft_check(k, sign, deque));
}