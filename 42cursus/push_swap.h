/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoshin <seoshin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:09:03 by seoshin           #+#    #+#             */
/*   Updated: 2023/03/06 18:28:28 by seoshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct node
{
	struct node	*next;
	struct node	*prev;
	int			data;
}t_node;

typedef struct deque
{
	t_node	*top;
	t_node	*bottom;
	int		cnt;
}t_deque;

int		is_one(int num, t_deque *deque);
int		is_int(char **av);
int		is_sorted(char **av, t_deque *deque);
int		ft_atoi(const char *str, t_deque *deque);
int		*input(char **av, t_deque *deque);
void	put_arr(int *arr, t_deque *deque);
void	node_clear(t_deque *deque);
void	print_emsg(t_deque *deque);
int		is_empty(t_deque *deque);
void	deque_init(t_deque *deque);
void	append(t_deque *deque, int data);
int		pop_left(t_deque *deque);
void	append_left(t_deque *deque, int data);
int		pop(t_deque *deque);
void	pa(t_deque *a, t_deque *b);
void	pb(t_deque *a, t_deque *b);
void	sa(t_deque *a);
void	sb(t_deque *b);
void	ss(t_deque *a, t_deque *b);
void	ra(t_deque *a);
void	rb(t_deque *b);
void	rr(t_deque *a, t_deque *b);
void	rra(t_deque *a);
void	rrb(t_deque *b);
void	rrr(t_deque *a, t_deque *b);
void	q_sort(int *arr, int start, int end);
void	send_to_b(t_deque *a, t_deque *b, int *pivot);
void	greedy(t_deque *a, t_deque *b);
int		loc_a(t_deque *a, int num);
int		cmp_n_update(int da, int db, int a_location, int b_location);
void	final_sort(t_deque *a);
void	sort_two(t_deque *a);
void	sort_three(t_deque *a);
void	sort_four(t_deque *a, t_deque *b, int *arr);
void	sort_five(t_deque *a, t_deque *b, int *arr);
void	sort_small(t_deque *a, t_deque *b, int *arr);
void	sort_big(t_deque *a, t_deque *b, int *arr, int *pivot);

#endif