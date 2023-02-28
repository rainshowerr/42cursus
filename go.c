/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:22:38 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 22:37:32 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_deque *a)
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

// 수정고고
static void	sort_big(t_deque *a, t_deque *b, int *pivot)
{
	send_to_b(a, b, pivot);
	if (a->cnt == 2)
		sort_two(a);
	else if (a->cnt == 3)
		sort_three(a);
}

void	go(t_deque *a, t_deque *b, int *pivot)
{
	if (a->cnt == 2)
		sort_two(a);
	else if (a->cnt == 3)
		sort_three(a);
	else if (a->cnt > 3)
		sort_big(a, b, pivot);
}
