/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 18:27:16 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/06 18:28:49 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_one(int num, t_deque *deque)
{
	t_node	*node;

	node = deque->top;
	while (node)
	{
		if (node->data == num)
			print_emsg(deque);
		node = node->next;
	}
	return (1);
}

int	is_int(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0')
			return (0);
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			return (0);
		while (av[i][j])
		{
			if (av[i][j] < '0' || '9' < av[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(char **av, t_deque *deque)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i + 1] && ft_atoi(av[i], deque) > ft_atoi(av[i + 1], deque))
			return (0);
		i++;
	}
	return (1);
}
