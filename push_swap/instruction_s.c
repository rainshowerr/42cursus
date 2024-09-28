/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:40:45 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 20:24:08 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_deque *a)
{
	int	first;
	int	second;

	if (a->cnt <= 1)
		return ;
	first = a->top->data;
	second = a->top->next->data;
	a->top->data = second;
	a->top->next->data = first;
	write(1, "sa\n", 3);
}

void	sb(t_deque *b)
{
	int	first;
	int	second;

	if (b->cnt <= 1)
		return ;
	first = b->top->data;
	second = b->top->next->data;
	b->top->data = second;
	b->top->next->data = first;
	write(1, "sb\n", 3);
}

void	ss(t_deque *a, t_deque *b)
{
	int	first;
	int	second;

	if (a->cnt <= 1 || b->cnt <= 1)
		return ;
	first = a->top->data;
	second = a->top->next->data;
	a->top->data = second;
	a->top->next->data = first;
	first = b->top->data;
	second = b->top->next->data;
	b->top->data = second;
	b->top->next->data = first;
	write(1, "ss\n", 3);
}
