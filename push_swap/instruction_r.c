/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:36:31 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 20:22:53 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_deque *a)
{
	int	data;

	data = pop_left(a);
	append(a, data);
	write(1, "ra\n", 3);
}

void	rb(t_deque *b)
{
	int	data;

	data = pop_left(b);
	append(b, data);
	write(1, "rb\n", 3);
}

void	rr(t_deque *a, t_deque *b)
{
	int	data;

	data = pop_left(a);
	append(a, data);
	data = pop_left(b);
	append(b, data);
	write(1, "rr\n", 3);
}
