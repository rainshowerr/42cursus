/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:40:45 by seoshin           #+#    #+#             */
/*   Updated: 2023/02/17 18:40:45 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void sa(t_deque *a)
{
	t_node *ptr;

	if (a->cnt <= 1)
		return;
	ptr = a->top; //ptr은 첫번째 노드를 가리킴
	ptr->next = a->top->next->next; // ptr의 next는 세번째 노드
	a->top = a->top->next; // 첫번째 노드를 두번째 노드로 바꿈
	a->top->prev = 0; // 원래 두번째 노드의 prev는 첫번째 노드인데, 두번째 노드가 첫번째 노드가 되었으니 prev = 0;
	a->top->next = ptr; // 두번째 노드는 ptr(첫번째 노드)를 가리킴
}
*/

void sa(t_deque *a)
{
	int first;
	int second;

	if (a->cnt <= 1)
		return;
	first = a->top->data;
	second = a->top->next->data;
	a->top->data = secont;
	a->top->next->data = first;
}

void sb(t_deque *b)
{
	int first;
	int second;

	if (b->cnt <= 1)
		return;
	first = b->top->data;
	second = b->top->next->data;
	b->top->data = secont;
	b->top->next->data = first;
}

void ss(t_deque *a, t_deque *b)
{
	sa(a);
	sb(b);
}