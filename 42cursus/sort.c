/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:35:26 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/06 18:26:05 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_deque *a, t_deque *b, int *arr)
{
	if (a->cnt == 2)
		sort_two(a);
	else if (a->cnt == 3)
		sort_three(a);
	if (a->cnt == 4)
		sort_four(a, b, arr);
	else if (a->cnt == 5)
		sort_five(a, b, arr);
	if (a->cnt <= 5)
	{
		node_clear(a);
		free(arr);
		exit(0);
	}
}

void	sort_big(t_deque *a, t_deque *b, int *arr, int *pivot)
{
	pivot[0] = arr[a->cnt / 3];
	pivot[1] = arr[a->cnt / 3 * 2];
	send_to_b(a, b, pivot);
	if (a->cnt == 2)
		sort_two(a);
	else if (a->cnt == 3)
		sort_three(a);
}
