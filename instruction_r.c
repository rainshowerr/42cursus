/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:36:31 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/24 05:58:29 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a)
{
	int data;

	data = pop_left(a);
	append(a, data);
}

void	rb(t_deque *b)
{
	int data;

	data = pop_left(b);
	append(b, data);
}

void	rr(t_deque *a, t_deque *b)
{
	ra(a);
	rb(b);
}