/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/28 20:26:46 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char *av[])
{
	t_deque	a;
	t_deque	b;
	int		*arr;
	int		pivot[2];

	if (ac == 1)
		print_emsg(&a);
	deque_init(&a);
	deque_init(&b);
	input(ac, av, &a);
	arr = (int *)malloc(a.cnt * sizeof(int));
	if (!arr)
		return (0);
	put_arr(arr, &a);
	q_sort(arr, 0, a.cnt - 1);
	pivot[0] = arr[a.cnt / 3];
	pivot[1] = arr[a.cnt / 3 * 2];
	go(&a, &b, pivot);
	greedy(&a, &b);
	final_sort(&a);
	node_clear(&a);
	free(arr);
}
