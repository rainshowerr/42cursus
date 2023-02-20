/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:44:20 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/17 19:44:20 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_deque *a)
{
	int data;

	data = pop(a);
	append_left(a, data);
}

void rrb(t_deque *b)
{
	int data;

	data = pop(b);
	append_left(b, data);
}

void rrr(t_deque *a, t_deque *b)
{
	rra(a);
	rrb(b);
}