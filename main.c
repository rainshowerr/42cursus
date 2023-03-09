/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/06 18:38:53 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_deque	a;
	t_deque	b;
	int		*arr;
	int		pivot[2];

	deque_init(&a);
	deque_init(&b);
	if (ac == 1)
		return (0);
	arr = input(av, &a);
	sort_small(&a, &b, arr);
	sort_big(&a, &b, arr, pivot);
	greedy(&a, &b);
	final_sort(&a);
	node_clear(&a);
	free(arr);
}
