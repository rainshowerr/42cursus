/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/24 07:20:33 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// 이거 나중에 지우장
void	print_queue(t_deque *deque)
{
	t_node	*a;

	a = deque->top;
	while (a)
	{
		printf("%d ", a->data);
		a = a->next;
	}
	printf("\n");
}

void	send_to_b(t_deque *a, t_deque *b, int *pivot)
{
	t_node	*node;
	int		i;
	int		a_cnt;

	node = a->top;
	i = 0;
	a_cnt = a->cnt;
	while (i < a_cnt)
	{
		if (a->top->data <= pivot[1])
		{
			pb(a, b);
			if (b->top->data <= pivot[0])
				rb(b);
		}
		else
			ra(a);
		i++;
	}
	while (a->cnt > 3)
		pb(a, b);
}

int main(int ac, char *av[])
{
	t_deque	a;
	t_deque b;
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
	pivot[0] = arr[a.cnt/3];
	pivot[1] = arr[a.cnt/3 * 2];
	send_to_b(&a, &b, pivot);
	print_queue(&a);
	print_queue(&b);
	
}