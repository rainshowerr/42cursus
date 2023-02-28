/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:45:23 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 22:33:52 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void	sort_four(t_deque *a, t_deque *b)

{
	int		*arr;
	int		first;
	t_node	*node;

	arr = (int *)malloc(sizeof(int) * 4);
	put_arr(arr, a);
	q_sort(arr, 0, 3);
	first = arr[0];
	while (a->cnt > 3)
	{
		node = a->top;
		if (node->data == first)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	pa(a, b);
	node_clear(a);
	free(arr);
	exit(0);
}

void	sort_five(t_deque *a, t_deque *b)
{
	int		*arr;
	int		first;
	int		second;
	t_node	*node;

	arr = (int *)malloc(sizeof(int) * 5);
	put_arr(arr, a);
	q_sort(arr, 0, 4);
	first = arr[0];
	second = arr[1];
	while (a->cnt > 3)
	{
		node = a->top;
		if (node->data == first || node->data == second)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	if (b->top->data == first)
		sb(b);
	pa(a, b);
	pa(a, b);
	node_clear(a);
	free(arr);
}
