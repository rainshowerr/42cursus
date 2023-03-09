/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:23:45 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/06 16:30:11 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_node *node)
{
	int	num;

	num = node->data;
	while (node)
	{
		if (num < node->data)
			num = node->data;
		node = node->next;
	}
	return (num);
}

static int	find_max_index(t_deque *a, int max)
{
	int		idx;
	t_node	*node;

	node = a->top;
	idx = 0;
	while (node)
	{
		if (node->data == max)
			break ;
		idx++;
		node = node->next;
	}
	if (idx >= a->cnt / 2)
		idx -= a->cnt;
	return (idx);
}

static void	final_loc(t_deque *a, int max_idx)
{
	int	cnt;

	max_idx++;
	cnt = max_idx;
	while (max_idx > 0 && cnt > 0)
	{
		ra(a);
		cnt--;
	}
	while (max_idx < 0 && cnt < 0)
	{
		rra(a);
		cnt++;
	}
}

void	final_sort(t_deque *a)
{
	int	max;
	int	max_idx;

	max = find_max(a->top);
	max_idx = find_max_index(a, max);
	final_loc(a, max_idx);
}
