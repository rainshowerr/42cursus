/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loc_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:10:25 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 20:31:44 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	loc_a(t_deque *a, int num)
{
	int		cnt;
	t_node	*node;

	cnt = 0;
	node = a->top;
	while (node)
	{
		if (node->prev == NULL && a->bottom->data < num && num < node->data)
			break ;
		if (node->prev != NULL && node->prev->data > num && \
			node->data > num && node->prev->data > node->data)
			break ;
		if (node->prev != NULL && node->prev->data < num && \
			node->data > num && node->prev->data < node->data)
			break ;
		if (node->prev != NULL && node->prev->data < num && \
			node->data < num && node->prev->data > node->data)
			break ;
		node = node->next;
		cnt++;
	}
	if (cnt > a->cnt / 2)
		cnt = cnt - a->cnt;
	return (cnt);
}
