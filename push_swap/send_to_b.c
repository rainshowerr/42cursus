/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:56:30 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 20:27:15 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_b(t_deque *a, t_deque *b, int *pivot)
{
	int		i;
	int		a_cnt;

	i = 0;
	a_cnt = a->cnt;
	while (i < a_cnt)
	{
		if (a->top->data <= pivot[1])
		{
			pb(a, b);
			if (b->top->data <= pivot[0])
				rb(b);
		}
		else
			ra(a);
		i++;
	}
	while (a->cnt > 3)
		pb(a, b);
}
