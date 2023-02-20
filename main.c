/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/17 19:46:15 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void str_to_int(int ac, char *av, t_deque *deque)
{
	int		i;

	i = 1;
	while (i < ac)
		enqueue(deque, ft_atoi(av[i++]));
}

int main(int ac, char *av[])
{
	t_deque	a;
	t_deque b;

	deque_init(&a);
	deque_init(&b);
	str_to_int(ac, av, &a);
	
}