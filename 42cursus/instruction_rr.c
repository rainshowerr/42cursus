/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:44:20 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 20:23:11 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_deque *a)
{
	int	data;

	data = pop(a);
	append_left(a, data);
	write(1, "rra\n", 4);
}

void	rrb(t_deque *b)
{
	int	data;

	data = pop(b);
	append_left(b, data);
	write(1, "rrb\n", 4);
}

void	rrr(t_deque *a, t_deque *b)
{
	int	data;

	data = pop(a);
	append_left(a, data);
	data = pop(b);
	append_left(b, data);
	write(1, "rrr\n", 4);
}
