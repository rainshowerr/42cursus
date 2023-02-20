/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:16 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/17 19:46:05 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int	is_empty(t_deque *deque)
{
	if (deque->cnt == 0)
		return (1);
	return (0);
}

void deque_init(t_deque *deque)
{
	deque->cnt = 0;
	deque->top = 0;
	deque->bottom = 0;
}

void append(t_deque *deque, int data)
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

int pop_left(t_deque *deque)
{
	t_node	*ptr;
	int		data;

	if (is_empty(deque))
		print_emsg("pop_left error is occured\n");
	ptr = deque->top;
	data = ptr->data;
	deque->top = ptr->next;
	deque->top->prev = 0;
	deque->cnt--;
	free(ptr);
	return (data);
}

void append_left(t_deque *deque, int data)
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

int pop(t_deque *deque)
{
	t_node	*ptr;
	int		data;

	if (is_empty(deque))
		print_emsg("pop error is occured\n");
	ptr = deque->bottom;
	data = ptr->data;
	deque->bottom = ptr->prev;
	deque->bottom->next = 0;
	deque->cnt--;
	free(ptr);
	return (data);
}