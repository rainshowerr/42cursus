/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:10 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/24 15:48:57 by seoshin          ###   ########.fr       */
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

int	find_place_a(t_deque *a, int num)
{
	int		cnt;
	t_node	node;

	cnt = 0;
	node = a->top;
	while(node)
	{
		// 맨 위 위치할 경우
		if (node->prev == NULL && node->data > find)
			break ;
		// 삼각형 사이에 낑김 (작은 삼각형의 시작)
		if (node->prev != NULL && node->prev->data > find && \
			node->data > find && node->prev->data > node->data)
			break ;
		// 한 삼각형 사이에 잘 위치
		if (node->prev != NULL && node->prev->data < find && \
			node->data > find && node->prev->data < node->data)
			break ;
		// 삼각형 사이에 낑김 (큰 삼각형의 마지막)
		if (node->prev != NULL && node->prev->data < find && \
			node->data < find && node->prev->data > node->Data)
			break;
		node = node->next;
		cnt++;
	}
	// cnt가 음수가 되면 rra?
	if (cnt > a->size / 2)
		cnt = cnt - a->cnt;
	return (cnt);
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