/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:07:25 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/17 19:07:25 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_deque *a, t_deque *b)
{
	int data;

	if (is_empty(b))
		return;
	data = pop_left(b);
	append_left(ptr, data);
}

void pb(t_deque *a, t_deque *b)
{
	int data;

	if (is_empty(a))
		return;
	data = pop_left(a);
	append_left(ptr, data);
}
