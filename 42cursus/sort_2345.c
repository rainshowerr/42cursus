/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2345.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:45:23 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/06 18:25:48 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_deque *a)
{
	if (a->top->data > a->top->next->data)
		sa(a);
}

void	sort_three(t_deque *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->data;
	second = a->top->next->data;
	third = a->bottom->data;
	if (first > second && second < third && third > first)
		sa(a);
	if (first > second && second > third && third < first)
	{
		sa(a);
		rra(a);
	}
	if (first > second && second < third && third < first)
		ra(a);
	if (first < second && second > third && third > first)
	{
		sa(a);
		ra(a);
	}
	if (first < second && second > third && third < first)
		rra(a);
}

void	sort_four(t_deque *a, t_deque *b, int *arr)

{
	int		first;
	t_node	*node;

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
}

void	sort_five(t_deque *a, t_deque *b, int *arr)
{
	int		first;
	int		second;
	t_node	*node;

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
}
