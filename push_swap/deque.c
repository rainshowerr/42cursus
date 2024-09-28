/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:16 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 20:15:00 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_empty(t_deque *deque)
{
	if (deque->cnt == 0)
		return (1);
	return (0);
}

void	append(t_deque *deque, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->next = 0;
	node->prev = 0;
	node->data = data;
	if (is_empty(deque))
		deque->top = node;
	else
	{
		node->prev = deque->bottom;
		deque->bottom->next = node;
	}
	deque->bottom = node;
	deque->cnt++;
}

int	pop_left(t_deque *deque)
{
	t_node	*ptr;
	int		data;

	if (is_empty(deque))
		print_emsg(deque);
	ptr = deque->top;
	data = ptr->data;
	deque->top = ptr->next;
	if (deque->top != 0)
		deque->top->prev = 0;
	deque->cnt--;
	free(ptr);
	return (data);
}

void	append_left(t_deque *deque, int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	node->next = 0;
	node->prev = 0;
	node->data = data;
	if (is_empty(deque))
		deque->bottom = node;
	else
	{
		node->next = deque->top;
		deque->top->prev = node;
	}
	deque->top = node;
	deque->cnt++;
}

int	pop(t_deque *deque)
{
	t_node	*ptr;
	int		data;

	if (is_empty(deque))
		print_emsg(deque);
	ptr = deque->bottom;
	data = ptr->data;
	deque->bottom = ptr->prev;
	if (deque->bottom != 0)
		deque->bottom->next = 0;
	deque->cnt--;
	free(ptr);
	return (data);
}
