/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:12:37 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 20:10:18 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rot_ab(t_deque *a, t_deque *b, int *da, int *db)
{
	while (*da && *db && (*da < 0 && *db < 0))
	{
		*da += 1;
		*db += 1;
		rrr(a, b);
	}
	while (*da && *db && (*da > 0 && *db > 0))
	{
		*da -= 1;
		*db -= 1;
		rr(a, b);
	}
}

static void	rot_a(t_deque *a, int da)
{
	while (da < 0)
	{
		da += 1;
		rra(a);
	}
	while (da > 0)
	{
		da -= 1;
		ra(a);
	}
}

static void	rot_b(t_deque *b, int db)
{
	while (db < 0)
	{
		db += 1;
		rrb(b);
	}
	while (db > 0)
	{
		db -= 1;
		rb(b);
	}
}

static void	get_min(t_deque *a, t_deque *b, int *da, int *db)
{
	int			idx;
	int			data;
	int			a_location;
	int			b_location;
	t_node		*temp;

	idx = 0;
	temp = b->top;
	while (idx < b->cnt)
	{
		data = temp->data;
		a_location = loc_a(a, data);
		if (idx > b->cnt / 2)
			b_location = idx - b->cnt;
		else
			b_location = idx;
		if (!idx || cmp_n_update(*da, *db, a_location, b_location))
		{
			*da = a_location;
			*db = b_location;
		}
		temp = temp->next;
		idx++;
	}
}

void	greedy(t_deque *a, t_deque *b)
{
	int	data_a;
	int	data_b;

	while (b->cnt)
	{
		get_min(a, b, &data_a, &data_b);
		rot_ab(a, b, &data_a, &data_b);
		rot_a(a, data_a);
		rot_b(b, data_b);
		pa(a, b);
	}
}
