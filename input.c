/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:18:29 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/06 18:27:27 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	str_to_int(char **av, t_deque *deque)
{
	int	i;
	int	num;

	i = 1;
	while (av[i])
	{
		num = ft_atoi(av[i++], deque);
		if (is_one(num, deque))
			append(deque, num);
	}
}

int	*input(char **av, t_deque *deque)
{
	int	*arr;

	if (!is_int(av))
		print_emsg(deque);
	str_to_int(av, deque);
	if (is_sorted(av, deque))
	{
		node_clear(deque);
		exit(1);
	}
	arr = (int *)malloc(deque->cnt * sizeof(int));
	if (!arr)
	{
		node_clear(deque);
		exit(1);
	}
	put_arr(arr, deque);
	q_sort(arr, 0, deque->cnt - 1);
	return (arr);
}

void	put_arr(int *arr, t_deque *deque)
{
	t_node	*node;
	int		i;

	node = deque->top;
	i = 0;
	while (node)
	{
		arr[i] = node->data;
		node = node->next;
		i++;
	}
}
